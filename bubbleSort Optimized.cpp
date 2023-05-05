#include<iostream>
using namespace std;

void bubblesort(int arr[] , int n ){
    bool swapped;
    int count = 0 ;
    for ( int i = 0; i < n - 1; i++){
        swapped = false;
        for( int j = 0; j < n - i - 1; j++){
            count++;
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);        
                swapped = true;
            }
        }
    if(swapped == false)
        break;
    }
    cout <<"Iteration Count :" << count << endl; // n(n-1)/2
    
}

void printArray( int arr[] , int n ){
        for( int i = 0; i < n; i++){
            cout << arr[i] <<" ";
        }
}
int main(){
    int arr[] = { 3,4,8,5,10,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr , n);
    cout << "Sorted Array using OP BUBBLE :";
    printArray(arr , n);
return 0;
}
