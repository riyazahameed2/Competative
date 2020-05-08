#include<iostream>
using namespace std;

void insertionSort(int arr[], int size){
    int i, key, j;
    for(i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int n,i;
    cout<<"Enter the size of Array: ";
    cin>>n;
    int arr[n];
    cout<<"\n Enter the Array: ";
    for(i = 0; i < n; i++){
        cin>>arr[i];
    }
    insertionSort(arr, n);
    cout<<"Array After Sorting: \n";
    for (i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}
