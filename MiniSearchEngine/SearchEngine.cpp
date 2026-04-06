#include <iostream>
#include <string>
#include <vector>
#include "DocumentLoader.h"
using namespace std;
class SearchEngine {
    public:
    vector<string> documents;

    void loadDocuments();

    void displayDocuments();
};

void SearchEngine::loadDocuments() {
    DocumentLoader loader;

    // List of files (you can later make this dynamic)
    vector<string> files = {"doc1.txt", "doc2.txt", "doc3.txt"};

    for (string file : files) {
        string content = loader.readFile(file);

        // Store only if file is not empty
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