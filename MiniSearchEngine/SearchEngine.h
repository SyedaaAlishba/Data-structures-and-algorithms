#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <vector>
#include <string>
using namespace std;

class SearchEngine {
private:
    vector<string> documents;   // stores all documents

public:
    void loadDocuments();
    void displayDocuments();
};

#endif
