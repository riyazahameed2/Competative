#include <iostream>
using namespace std;
#define vertices 4
#define infinity 9999

void displayMatrix(int array[][vertices]);

void floydWarshall(int graph[][vertices]){
  int array[vertices][vertices], i, j, k;
  for (i = 0; i < vertices; i++)
    for (j = 0; j < vertices; j++)
      array[i][j] = graph[i][j];
  for (k = 0; k < vertices; k++){
    for (i = 0; i < vertices; i++){
      for (j = 0; j < vertices; j++){
        if (array[i][k] + array[k][j] < array[i][j])
          array[i][j] = array[i][k] + array[k][j];
      }
    }
  }
  displayMatrix(array);
}

void displayMatrix(int array[][vertices]){
  for (int i = 0; i < vertices; i++){
    for (int j = 0; j < vertices; j++){
      if (array[i][j] == infinity)
        cout << "infinity"
           << "  ";
      else
        cout << array[i][j] << "  ";
    }
    cout << endl;
  }
}

int main(){
  int graph[vertices][vertices] = {{0, 3, infinity, 5},
             {2, 0, infinity, 4},
             {infinity, 1, 0, infinity},
             {infinity, infinity, 2, 0}};
  floydWarshall(graph);
}
