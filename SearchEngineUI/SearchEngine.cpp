#include "SearchEngine.h"
#include "DocumentLoader.h"
#include "FileCrawler.h"
#include "Tries.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <unordered_set>

using namespace std;

// Global Trie + unique word tracker
Trie trie;
unordered_set<string> uniqueWords;

// ---------------- LOAD DOCUMENTS ----------------
void SearchEngine::loadDocuments()
{
    DocumentLoader loader;
    FileCrawler crawler;

    vector<string> files = crawler.getFiles("./data");

    int docID = 0;

    for (string file : files)
    {
        string content = loader.readFile(file);

        if (!content.empty())
        {
            Document doc;
            doc.id = docID;
            doc.filename = file;
            doc.content = content;

            documents.push_back(doc);
            docID++;
        }
    }
}

// ---------------- TOKENIZER ----------------
vector<string> SearchEngine::tokenize(string text)
{
    vector<string> words;

    transform(text.begin(), text.end(), text.begin(), ::tolower);

    stringstream ss(text);
    string word;

    while (ss >> word)
    {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        if (!word.empty())
            words.push_back(word);
    }

    return words;
}

// ---------------- DISPLAY ----------------
void SearchEngine::displayDocuments()
{
    for (int i = 0; i < documents.size(); i++)
    {
        cout << "ID: " << documents[i].id << "\n";
        cout << "File: " << documents[i].filename << "\n";
        cout << documents[i].content << "\n\n";
    }
}

// ---------------- BUILD INDEX ----------------
void SearchEngine::buildIndex()
{
    for (int docId = 0; docId < documents.size(); docId++)
    {
        vector<string> words = tokenize(documents[docId].content);

        for (string word : words)
        {
            index.insert(word, docId);

            if (uniqueWords.find(word) == uniqueWords.end())
            {
                trie.insert(word);
                uniqueWords.insert(word);
            }
        }
    }
}

// ---------------- SEARCH MAIN ----------------
vector<int> SearchEngine::search(const string& query)
{
    if (query.empty())
        return {};

    // ---------------- PHRASE SEARCH ----------------
    if (query.size() >= 2 &&
        query.front() == '"' &&
        query.back() == '"')
    {
        string phrase = query.substr(1, query.size() - 2);
        return phraseSearch(phrase);
    }

    string lowerQuery = query;
    transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

    // ---------------- OR SEARCH ----------------
    if (lowerQuery.find(" or ") != string::npos)
    {
        vector<string> queryWords;
        stringstream ss(lowerQuery);
        string word;

        while (ss >> word)
        {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

            if (word != "or" && !word.empty())
                queryWords.push_back(word);
        }

        vector<int> docs = orSearch(queryWords);
        return docs;
    }

    // ---------------- AND SEARCH ----------------
    vector<string> queryWords;
    stringstream ss(query);
    string word;

    while (ss >> word)
    {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (!word.empty() && word != "or")
            queryWords.push_back(word);
    }

    if (queryWords.empty())
        return {};

    vector<int> result = index.search(queryWords[0]);

    for (int i = 1; i < queryWords.size(); i++)
    {
        vector<int> current = index.search(queryWords[i]);
        vector<int> temp;

        for (int id : result)
        {
            if (find(current.begin(), current.end(), id) != current.end())
                temp.push_back(id);
        }

        result = temp;
    }

    return result;
}

// ---------------- PHRASE SEARCH ----------------
vector<int> SearchEngine::phraseSearch(const string& phrase)
{
    vector<int> result;

    string cleanPhrase = phrase;
    transform(cleanPhrase.begin(), cleanPhrase.end(), cleanPhrase.begin(), ::tolower);
    cleanPhrase.erase(remove_if(cleanPhrase.begin(), cleanPhrase.end(), ::ispunct), cleanPhrase.end());

    for (int i = 0; i < documents.size(); i++)
    {
        string doc = documents[i].content;

        transform(doc.begin(), doc.end(), doc.begin(), ::tolower);
        doc.erase(remove_if(doc.begin(), doc.end(), ::ispunct), doc.end());

        if (containsPhrase(doc, cleanPhrase))
            result.push_back(i);
    }

    return result;
}

// ---------------- HELPER ----------------
bool SearchEngine::containsPhrase(const string& text, const string& phrase)
{
    return text.find(phrase) != string::npos;
}

// ---------------- OR SEARCH ----------------
vector<int> SearchEngine::orSearch(vector<string> queryWords)
{
    vector<int> result;

    for (string w : queryWords)
    {
        vector<int> docs = index.search(w);

        for (int id : docs)
        {
            if (find(result.begin(), result.end(), id) == result.end())
                result.push_back(id);
        }
    }

    return result;
}

// ---------------- RANK RESULTS ----------------
vector<SearchResult> SearchEngine::rankResults(vector<int> docs, string query)
{
    vector<SearchResult> ranked;

    vector<string> queryWords;
    stringstream ss(query);
    string word;

    while (ss >> word)
    {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (!word.empty() && word != "or")
            queryWords.push_back(word);
    }

    for (int id : docs)
    {
        int score = 0;

        for (string w : queryWords)
            score += index.getFrequency(w, id);

        SearchResult res;
        res.docID = id;
        res.filename = documents[id].filename;
        res.score = score;

        ranked.push_back(res);
    }

    sort(ranked.begin(), ranked.end(),
         [](SearchResult a, SearchResult b)
         {
             return a.score > b.score;
         });

    return ranked;
}

// ---------------- SEARCH WITH RANKING ----------------
vector<SearchResult> SearchEngine::searchWithRanking(const string& query)
{
    vector<int> docs = search(query);
    return rankResults(docs, query);
}

// ---------------- AUTOCOMPLETE ----------------
vector<string> SearchEngine::getSuggestions(string prefix)
{
    vector<string> result;

    if (prefix.empty())
        return result;

    transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);

    return trie.getSuggestions(prefix);
}
vector<Document> SearchEngine::getDocuments()
{
    return documents;
}