#include "SearchEngine.h"
#include "DocumentLoader.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

void SearchEngine::loadDocuments() {
    DocumentLoader loader;

    // You can later make this dynamic
    vector<string> files = {"doc1.txt.txt", "doc2.txt.txt", "doc3.txt.txt", "doc4.txt.txt"};

    for (string file : files) {
        string content = loader.readFile(file);

        if (content != "") {
            documents.push_back(content);
        }
    }
}

vector<string> SearchEngine::tokenize(string text)
{
    vector<string> words;

    // convert to lowercase
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    stringstream ss(text);
    string word;

    while (ss >> word)
    {
        // remove punctuation
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        // ignore empty words
        if (!word.empty())
            words.push_back(word);
    }

    return words;
}
void SearchEngine::displayDocuments() {
    for (int i = 0; i < documents.size(); i++) {
        cout << "Document " << i + 1 << ":\n";
        cout << documents[i] << "\n\n";
    }
}
void SearchEngine::buildIndex()
{
    for (int docId = 0; docId < documents.size(); docId++)
    {
        // tokenize each document
        vector<string> words = tokenize(documents[docId]);

        for (string word : words)
        {
            index.insert(word, docId);
        }
    }
}
vector<int> SearchEngine::search(string query)
{
    vector<int> result;

    // phrase search
    if (query.front() == '"' && query.back() == '"')
    {
        query = query.substr(1, query.size() - 2);
        vector<int> res = phraseSearch(query);

        vector<pair<int,int>> ranked = rankResults(res, query);

        vector<int> finalResult;
        for (auto p : ranked)
            finalResult.push_back(p.first);

        return finalResult;
    }

    transform(query.begin(), query.end(), query.begin(), ::tolower);

    // OR search
    if (query.find(" or ") != string::npos)
    {
        stringstream ss(query);
        string word;
        vector<string> queryWords;

        while (ss >> word)
        {
            if (word != "or")
                queryWords.push_back(word);
        }

        vector<int> docs = orSearch(queryWords);

        vector<pair<int,int>> ranked = rankResults(docs, query);

        vector<int> finalResult;
        for (auto p : ranked)
            finalResult.push_back(p.first);

        return finalResult;
    }

    // AND search
    stringstream ss(query);
    string word;
    vector<string> queryWords;

    while (ss >> word)
        queryWords.push_back(word);

    if (queryWords.empty())
        return {};

    result = index.search(queryWords[0]);

    for (int i = 1; i < queryWords.size(); i++)
    {
        vector<int> currentDocs = index.search(queryWords[i]);

        vector<int> temp;

        for (int id : result)
        {
            if (find(currentDocs.begin(), currentDocs.end(), id) != currentDocs.end())
                temp.push_back(id);
        }

        result = temp;
    }

    vector<pair<int,int>> ranked = rankResults(result, query);

    vector<int> finalResult;
    for (auto p : ranked)
        finalResult.push_back(p.first);

    return finalResult;
}
vector<int> SearchEngine::phraseSearch(string phrase)
{
    vector<int> result;

    transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
    phrase.erase(remove_if(phrase.begin(), phrase.end(), ::ispunct), phrase.end());

    for (int i = 0; i < documents.size(); i++)
    {
        string doc = documents[i];

        transform(doc.begin(), doc.end(), doc.begin(), ::tolower);

        if (containsPhrase(doc, phrase))
        {
            result.push_back(i);
        }
    }

    return result;
}
bool SearchEngine::containsPhrase(string text, string phrase)
{
    return text.find(phrase) != string::npos;
}
vector<int> SearchEngine::orSearch(vector<string> queryWords)
{
    vector<int> result;

    for (string w : queryWords)
    {
        vector<int> docs = index.search(w);

        for (int id : docs)
        {
            // avoid duplicates
            if (find(result.begin(), result.end(), id) == result.end())
            {
                result.push_back(id);
            }
        }
    }

    return result;
}
vector<pair<int,int>> SearchEngine::rankResults(vector<int> docs, string query)
{
    vector<pair<int,int>> ranked;

    // convert query → words
    vector<string> queryWords;
    stringstream ss(query);
    string word;

    while (ss >> word)
        queryWords.push_back(word);

    for (int id : docs)
    {
        int score = 0;

        for (string w : queryWords)
        {
            score += index.getFrequency(w, id);
        }

        ranked.push_back({id, score});
    }

    sort(ranked.begin(), ranked.end(),
        [](pair<int,int> a, pair<int,int> b)
        {
            return a.second > b.second;
        });

    return ranked;
}