#include "SearchEngine.h"
#include "DocumentLoader.h"
#include <iostream>

using namespace std;

void SearchEngine::loadDocuments() {
    DocumentLoader loader;

    // You can later make this dynamic
    vector<string> files = {"doc1.txt", "doc2.txt", "doc3.txt"};

    for (string file : files) {
        string content = loader.readFile(file);

        if (content != "") {
            documents.push_back(content);
        }
    }
}

void SearchEngine::displayDocuments() {
    for (int i = 0; i < documents.size(); i++) {
        cout << "Document " << i + 1 << ":\n";
        cout << documents[i] << "\n\n";
    }
}
void SearchEngine::displayDocuments() {
    for (int i = 0; i < documents.size(); i++) {
        cout << "Document " << i + 1 << ":\n";
        cout << documents[i] << "\n\n";
    }
}
