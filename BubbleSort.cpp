#include<iostream>
using namespace std;

void swap(int *ab,int *ac){
    int temp = *ab;
    *ab = *ac;
    *ac = temp;
}

void bubbleSort(int arr[], int num){
    int i, j;
    bool swapped;
    for(i = 0; i < num - 1; i++){
            swapped = false;
            for(j = 0; j< num - i - 1; j++){
                if(arr[j] > arr[j + 1]){
                    swap(&arr[j], &arr[j+1]);
                    swapped = true;
                }
            }
        if(swapped == false){
            break;
        }
    }
}

/*void displayArray(int arr[], int size){
    int i;
    cout<<"Size of array is : "<<size;

}*/

int main(){
    int n, i;
    cout<<"Enter the size of Array: ";
    cin>>n;
    int arr[n];
    cout<<"\n Enter the Array: ";
    for(i = 0; i < n; i++){
        cin>>arr[i];
    }
    bubbleSort(arr, n);
    cout<<"Array After Sorting: \n";
    for (i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}
