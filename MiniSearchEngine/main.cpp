#include <iostream>
#include <limits>
#include <algorithm>
#include "SearchEngine.h"
using namespace std;

// 🔥 Query validation
bool isValidQuery(string query)
{
    string temp = query;

    // remove spaces
    temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());

    // remove punctuation
    temp.erase(remove_if(temp.begin(), temp.end(), ::ispunct), temp.end());

    return !temp.empty();
}

int main()
{
    SearchEngine engine;

    // Load + index
    engine.loadDocuments();
    engine.buildIndex();

    int choice;

    while (true)
    {
        cout << "\n====================================\n";
        cout << "      MINI SEARCH ENGINE \n";
        cout << "====================================\n";
        cout << "1. Show Documents\n";
        cout << "2. Search\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        // 🔥 Handle wrong input (abc, etc.)
        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(); // clear newline

        if (choice == 1)
        {
            cout << "\n===== DOCUMENTS =====\n";
            engine.displayDocuments();
        }
        else if (choice == 2)
        {
            string query;

            cout << "\nEnter search query: ";
            getline(cin, query);

            if (!isValidQuery(query))
            {
                cout << "Invalid query! Please enter meaningful words.\n";
                continue;
            }

            vector<int> docs = engine.search(query);
            vector<pair<int,int>> results = engine.rankResults(docs, query);

            if (results.empty())
            {
                cout << "\nNo documents found.\n";
            }
            else
            {
                cout << "\nResults:\n";
                cout << "------------------------------------\n";

                for (auto r : results)
                {
                    cout << "Document " << r.first + 1
                         << " (Score: " << r.second << ")\n";
                }
            }
        }
        else if (choice == 3)
        {
            cout << "\nExiting program...\n";
            break;
        }
        else
        {
            cout << "Invalid choice! Please select 1, 2, or 3.\n";
        }
    }

    return 0;
}