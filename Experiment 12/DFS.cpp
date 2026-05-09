#include <iostream>
using namespace std;

int graph[10][10], visited[10], n;

// DFS Function
void DFS(int node) {

    cout << node << " ";
    visited[node] = 1;

    for(int i = 0; i < n; i++) {

        if(graph[node][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "DFS Traversal: ";

    DFS(0);

    return 0;
}