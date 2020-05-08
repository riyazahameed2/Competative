#include<iostream>
using namespace std;

void swap(int *ab,int *ac){
    int temp = *ab;
    *ab = *ac;
    *ac = temp;
}

void selectionSort(int arr[], int size){
    int i, j, min;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for(j = i + 1; j < size; j++)
        if(arr[j] < arr[min])
            min = j;
        swap(&arr[min], &arr[i]);
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
    selectionSort(arr, n);
    cout<<"Array After Sorting: \n";
    for (i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;

}
