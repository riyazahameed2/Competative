#include<iostream>
using namespace std;

void swap(int *ab,int *ac){
    int temp = *ab;
    *ab = *ac;
    *ac = temp;
}

int partition (int arr[], int low, int high){
    int pivot, i, j;
    pivot = arr[high];
    i = (low - 1);
    for (j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    int parti;
    if (low < high){
         parti = partition(arr, low, high);
        quickSort(arr, low, parti - 1);
        quickSort(arr, parti + 1, high);
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
    quickSort(arr,0, n - 1);
    cout<<"Array After Sorting: \n";
    for (i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;

}
