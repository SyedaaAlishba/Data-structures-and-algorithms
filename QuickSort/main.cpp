#include <iostream>
using namespace std;


int  setPivot(int left, int right, int array[]) {
    int pivInd= (left+right)/2;
    //for first piv
    while (left<right) {
        while (pivInd<right) {
            if (array[right]>array[pivInd]) {
                right--;
            }else {
                swap(array[pivInd],array[right]);
                pivInd= right;
                break;
            }
        }
        //for right
        while (left<pivInd) {
            if (array[pivInd]>array[left]) {
                left++;
            }else {
                swap(array[pivInd],array[left]);
                pivInd= left;
                break;
            }
        }
    }

    return pivInd;

}


void QuickSort(int array[], int left, int right) {

    if (left<right) {
        int p=setPivot(left,right,array);
        QuickSort(array,left,p-1);
        QuickSort(array,p+1,right);
    }
}
int main() {
    int array[10]={22,92,17,18,11,78,67,52,85,90};
    QuickSort(array,0,9);
    for (int i=0;i<10;i++) {
        cout<<array[i]<<" ";
    }

}