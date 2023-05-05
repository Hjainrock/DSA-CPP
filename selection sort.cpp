#include<iostream>
using namespace std;
void swap(int* a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int main(){
    int arr[] = {7,3,5,13,2,5,6,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n << endl;
    for( int i = 0; i<n; i++){
        for( int j = i+1; j<n; j++){
            if(arr[j] < arr[i]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
    cout << "Sorted Array :";
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
return 0;
}
