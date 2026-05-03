#include <iostream>
using namespace std;

void insert(int heap[], int &size, int value) {
    heap[size] = value;   // last me insert
    int i = size;
    size++;

    // heapify up
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] < heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}
void heapifyDown(int heap[], int size, int i) {
    while (true) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

int deleteMax(int heap[], int &size) {
    if (size == 0) {
        cout << "Heap empty!\n";
        return -1;
    }

    int maxVal = heap[0];   // root save

    heap[0] = heap[size - 1];  // last element root pe
    size--;                    // size reduce

    heapifyDown(heap, size, 0);

    return maxVal;
}


int main() {
    int n;
    cout << "Enter size of heap: ";
    cin >> n;

    int heap[n];
    int size = 0;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        insert(heap, size, element);
    }

    cout << "Max Heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << "Deleted max: " << deleteMax(heap, size) << endl;

    cout << "Heap after deletion: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
}