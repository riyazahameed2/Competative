#include<iostream>
using namespace std;

#define SIZE 20
#define MAX 20


int queue[SIZE];
int qfront, qend;
void enqueue(int v);
int dequeue();

void bfs(int Adj[][MAX], int n, int source);

int main(void) {
    int Adj[][MAX] = {
        {1,1,0,0},
        {1,1,0,1},
        {0,0,1,1},
        {1,0,0,0}
    };
    int n = 4;
    int start_vertex = 2;
    bfs(Adj, n, start_vertex);
    return 0;
}

void bfs(int Adj[][MAX], int n, int source) {
    int i, j;
    int visited[MAX];
    qfront = 0;
    qend = 0;
    for(i = 0; i < MAX; i++) {
        visited[i] = 0;
    }
    visited[source] = 1;
    enqueue(source);
    cout<<source <<"\n";
    while(qfront <= qend) {
        i = dequeue();
        for(j = 0; j < n; j++) {
            if(visited[j] == 0 && Adj[i][j] == 1) {
                visited[j] = 1;
                enqueue(j);
                cout<<j<<"\n";
              }
        }
    }
    cout<<"\n";
}

void enqueue(int v) {
    queue[qend] = v;
    qend++;
}

int dequeue() {
    int index = qfront;
    qfront++;
    return queue[index];
}
