#include<iostream>
using namespace std;

int arr[10][10], visit[10], num;
void dfs(int i){
    int j;
    cout<<i<<"\n";
    visit[i] = 1;
    for(j = 0; j < num; j++){
        if(!visit[j] && arr[i][j] - 1){
            dfs(j);
        }
    }
}

int main(){
    int i, j;
    cout<<"Enter the No: of Vertices: \t";
    cin>>num;

    cout<<"Enter the adjacency matrix: \t";
    for(i = 0; i < num; i++){
       for(j = 0 ; j < num ; j++){
			cin>>arr[i][j];
       }
    }cout<<"\n\n";
    for(i = 0; i < num; i++){
       for(j = 0 ; j < num ; j++){
			cout<<arr[i][j]<<"\t";
       }cout<<"\n";
    }

    for(i = 0; i < num; i++){
        visit[i] = 0;
    }

    dfs(0);

}
