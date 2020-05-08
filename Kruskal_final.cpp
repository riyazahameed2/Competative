#include<iostream>
using namespace std;
#include<stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min_v, mincost = 0, cost[9][9], parent[9];
int find(int);
int unit(int,int);
int main(){
	cout<<"\nEnter the no. of Vertices:";
	cin>>n;
	cout<<"\nEnter the cost adjacency matrix:\n";
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			cin>>cost[i][j];
		}
	}
	cout<<"The edges of Minimum Cost Spanning Tree are\n";
	while(ne < n){
		for(i = 1,min_v = 500; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(cost[i][j] < min_v){
					min_v = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u = find(u);
		v = find(v);
		if(unit(u,v)){
                cout<< ne++ << "edge (" << a <<" , " << b << ") = " << min_v << "\n";
			mincost += min_v;
		}
		cost[a][b] = cost[b][a] = 500;
	}
	cout<<"\n\tMinimum cost = "<<mincost;

}
int find(int i){
	while(parent[i])
	i = parent[i];
	return i;
}
int unit(int i,int j){
	if(i != j){
		parent[j] = i;
		return 1;
	}
	return 0;
}
