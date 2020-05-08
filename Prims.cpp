#include<iostream>

using namespace std;

#define vertices 5

int minKey(int key[], bool mstSet[])  {
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++){
        if (mstSet[v] == false && key[v] < min){
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void displayMST(int parent[], int graph[vertices][vertices]) {
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < vertices; i++)  {
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
    }
}

void prim(int graph[vertices][vertices])  {
    int parent[vertices];
    int key[vertices];
    bool mstSet[vertices];
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }
   key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    displayMST(parent, graph);
}


int main()  {

    int graph[vertices][vertices] = { { 0, 6, 2, 1, 0 },  { 8, 0, 5, 1, 9 }, { 0, 5, 3, 7, 8 }, { 6, 8, 1, 1, 7 }, { 0, 5, 7, 9, 0 } };
    prim(graph);

    return 0;
}
