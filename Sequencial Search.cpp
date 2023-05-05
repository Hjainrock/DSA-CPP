#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // return the index where target is found
        }
    }
    return -1; // return -1 if target is not found in the array
}

int main() {
    int arr[] = {5, 8, 4, 6, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]); // calculate the size of the array
    int target = 4;
    int result = sequentialSearch(arr, n, target);
    if (result == -1) {
        cout << "Target not found in the array" << endl;
    } else {
        cout << "Target found at index " << result << endl;
    }
    return 0;
}
