#include "HashTable.h"

// Constructor
HashTable::HashTable()
{
    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;
}

// Hash Function
int HashTable::hashFunction(string key)
{
    int hash = 0;

    for (char c : key)
        hash = (hash * 31 + c) % SIZE;

    return hash;
}

// INSERT
void HashTable::insert(string word, int docID)
{
    int index = hashFunction(word);

    Node* ptr = table[index];

    while (ptr != NULL)
    {
        if (ptr->word == word)
        {
            // check if doc already exists
            for (auto &p : ptr->docFreq)
            {
                if (p.first == docID)
                {
                    p.second++; // increase frequency
                    return;
                }
            }

            // new doc
            ptr->docFreq.push_back({docID, 1});
            return;
        }

        ptr = ptr->next;
    }

    // new node
    Node* node = new Node;
    node->word = word;
    node->docFreq.push_back({docID, 1});
    node->next = table[index];

    table[index] = node;
}
// SEARCH
vector<int> HashTable::search(string word)
{
    int index = hashFunction(word);
    Node* ptr = table[index];
    while (ptr != NULL)
    {
        if (ptr->word == word)
        {
            vector<int> result;

            for (auto &p : ptr->docFreq)
                result.push_back(p.first);

            return result;
        }

        ptr = ptr->next;
    }
    return {};
}

// DISPLAY (DEBUG)
void HashTable::display()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Bucket " << i << ": ";

        Node* ptr = table[i];

        while (ptr != NULL)
        {
            cout << ptr->word << " -> ";
            ptr = ptr->next;
        }

        cout << "NULL\n";
    }
}
int HashTable::getFrequency(string word, int docID)
{
    int index = hashFunction(word);
    Node* ptr = table[index];
    while (ptr != NULL)
    {
        if (ptr->word == word)
        {
            for (auto &p : ptr->docFreq)
            {
                if (p.first == docID)
                    return p.second;
            }
        }
        ptr = ptr->next;
    }
    return 0;
}