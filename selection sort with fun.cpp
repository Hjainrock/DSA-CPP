#include<iostream>
using namespace std;
void swap(int* a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void selectionSort(int arr[] , int n){
   for( int i = 0; i<n; i++){
        for( int j = i+1; j<n; j++){
            if(arr[j] < arr[i]){
                swap(&arr[i],&arr[j]);

/*int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
*/
            }
        }
    }
}
void printArray(int arr[], int n){
    for ( int i = 0 ; i < n ; i++ ){
        cout << arr[i] << " ";
    }
}
int main(){
    int arr[] = {7,3,5,13,2,5,6,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n << endl;
    selectionSort(arr,n);
    cout << "Sorted Array :";
    printArray(arr,n);

return 0;
}

