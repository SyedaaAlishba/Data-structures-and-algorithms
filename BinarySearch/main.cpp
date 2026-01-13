#include <iostream>
using namespace std;

void BinarySearch(int array[], int size, int target) {
    bool flag = false;
    int mid;
    int left=0;
    int right= size-1;
    while(left<=right) {
        mid = (left+right)/2;
        if(array[mid] == target) {
            cout<<"Target found at index "<<mid<<endl;
            flag = true;
            break;
        }
        if (array[mid] < target) {
            left=mid+1;
        }else {
            right=mid-1;
        }
    }
    if (flag == false) {
        cout << "Target not found" << endl;
    }
}
int main() {

   int array[]={1,2,3,4,5,6,7,8,9,10};
    BinarySearch(array,10,7);

    return 0;
}