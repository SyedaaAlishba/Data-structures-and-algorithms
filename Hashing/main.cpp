#include <iostream>
using  namespace std;


#define SIZE 10
int hashArray[SIZE];
bool occupied[SIZE];
bool deleted[SIZE];



void initHashArray() {
       for (int i = 0; i < SIZE; i++) {
              hashArray[i] = 0;
              occupied[i] = false;
       }
}
int hashFunction(int val) {
       return val % SIZE;
}

void insertHashArray(int val) {
       int index = hashFunction(val);
       int startIndex = index;

       if (!occupied[index]) {
              hashArray[index] = val;
              occupied[index] = true;
              return;
       }
       do {
              index = (index + 1) % SIZE;

              if (index == startIndex) {
                     cout << "Hash table is full" << endl;
                     return;
              }
       } while (occupied[index]);

       hashArray[index] = val;
       occupied[index] = true;
}

void searchHashArray(int val) {
       int index = hashFunction(val);
       int startIndex = index;

       while (occupied[index]) {   // jab tak slot filled hai
              if (hashArray[index] == val) {
                     cout << "Found" << endl;
                     return;
              }

              index = (index + 1) % SIZE;

              if (index == startIndex)
                     break;
       }

       cout << "Not Found" << endl;
}

void deleteHashArray(int val) {
       int index = hashFunction(val);
       int startIndex = index;

       while (occupied[index] || deleted[index]) {

              if (occupied[index] && hashArray[index] == val) {
                     occupied[index] = false;
                     deleted[index] = true;   // mark as deleted
                     cout << "Deleted" << endl;
                     return;
              }

              index = (index + 1) % SIZE;

              if (index == startIndex)
                     break;
       }

       cout << "Not Found" << endl;
}

// // Display table
void display() {
       cout << "\nIndex\tValue\n";
       for (int i = 0; i < SIZE; i++) {
              cout << i << "\t";
              if (occupied[i]==false)
                     cout << "EMPTY";
              else
                     cout << hashArray[i];
              cout << endl;
       }
}



int main() {

        initHashArray();
        insertHashArray(1);
       insertHashArray(2);
       insertHashArray(3);
       insertHashArray(4);
       insertHashArray(5);
       searchHashArray(1);
       searchHashArray(2);
       deleteHashArray(1);
       deleteHashArray(2);
       searchHashArray(2);
       insertHashArray(3);
       insertHashArray(33);

       display();

}