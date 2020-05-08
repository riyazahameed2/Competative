#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 =  r - m;
    int Left[n1], Right[n2];
    for (i = 0; i < n1; i++)
        Left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (Left[i] <= Right[j]){
            arr[k] = Left[i];
            i++;
        }
        else{
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = Left[i];
        i++;
        k++;
    }
     while (j < n2){
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int m = left + (right - left ) / 2;
        mergeSort(arr, left, m);
        mergeSort(arr, m + 1, right);

        merge(arr, left, m, right);
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
    mergeSort(arr,0, n - 1);
    cout<<"Array After Sorting: \n";
    for (i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;

}

