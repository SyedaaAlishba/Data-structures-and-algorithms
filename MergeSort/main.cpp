#include <iostream>

#include <iostream>
using namespace std;

// merge function: two sorted parts ko combine karta hai
void merge(int arr[], int left, int mid, int right) {
    int size = right - left + 1;
    int temp[size];

    int i = left;      // left part pointer
    int j = mid + 1;   // right part pointer
    int k = 0;         // temp array pointer

    // compare both parts
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // left part ke bache hue elements
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // right part ke bache hue elements
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }


    for (int x = 0; x < size; x++) {
        arr[left + x] = temp[x];
    }
}


void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;   // base case

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
