#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HashTable
{
private:
    static const int SIZE = 10;

    struct Node
    {
        string word;
        vector<pair<int,int>> docFreq;
        Node* next;
    };

    Node* table[SIZE];

    int hashFunction(string key);

public:
    HashTable();
    void insert(string word, int docID);
    vector<int> search(string word);
    int getFrequency(string word, int docID);
    void display();
};

#endif