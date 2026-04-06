#include "DocumentLoader.h"
#include <fstream>
#include <iostream>

string DocumentLoader::readFile(string filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return "";
    }

    string line;
    string content = "";

    while (getline(file, line)) {
        content += line + " ";
    }

    file.close();
    return content;
}
