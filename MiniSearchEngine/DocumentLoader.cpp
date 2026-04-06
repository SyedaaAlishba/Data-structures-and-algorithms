
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class DocumentLoader {
public:
     string readFile(string filename);
};
string DocumentLoader::readFile(string filename) {
    ifstream file(filename);   // file open
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return "";
    }
    string line;
    string content = "";
    while (getline(file, line)) {
        content += line + " ";   // line ko add karo
    }
    file.close();
    return content;
}

