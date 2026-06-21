#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "HashTable.h"
#include <vector>
#include <string>
#include "Document.h"
#include "Tries.h"

using namespace std;

struct SearchResult
{
    int docID;
    string filename;
    int score;
};

class SearchEngine
{
private:
    vector<Document> documents;
    HashTable index;

    bool containsPhrase(const string& text, const string& phrase);
    vector<int> orSearch(vector<string> queryWords);
    vector<int> phraseSearch(const string& phrase);

public:
    void loadDocuments();
    vector<string> tokenize(string text);

    void buildIndex();
    void displayDocuments();

    vector<string> getSuggestions(string prefix);

    vector<int> search(const string& query);

    vector<SearchResult> rankResults(vector<int> docs, string query);
    vector<SearchResult> searchWithRanking(const string& query);
    vector<Document> getDocuments();
};

#endif