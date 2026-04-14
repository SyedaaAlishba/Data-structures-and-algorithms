#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "HashTable.h"
#include <vector>
#include <string>
using namespace std;

class SearchEngine {
private:
    vector<string> documents;
    HashTable index;

    bool containsPhrase(string text, string phrase);
    // vector<pair<int,int>> rankResults(vector<int> docs, string query);
    vector<int> orSearch(vector<string> queryWords);

public:
    void loadDocuments();
    vector<string> tokenize(string text);
    vector<int> search(string query);
    vector<int> phraseSearch(string phrase);
    vector<pair<int,int>> rankResults(vector<int> docs, string query);
    void displayDocuments();
    void buildIndex();
};

#endif