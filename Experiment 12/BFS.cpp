#include <iostream>
using namespace std;

int graph[10][10], visited[10], queueArr[10];
int front = -1, rear = -1, n;

// Enqueue
void enqueue(int val) {

    if(rear == 9)
        return;

    if(front == -1)
        front = 0;

    queueArr[++rear] = val;
}

// Dequeue
int dequeue() {

    if(front == -1 || front > rear)
        return -1;

    return queueArr[front++];
}

// BFS Function
void BFS(int start) {

    enqueue(start);
    visited[start] = 1;

    while(front <= rear) {

        int node = dequeue();

        cout << node << " ";

        for(int i = 0; i < n; i++) {

            if(graph[node][i] == 1 && visited[i] == 0) {

                enqueue(i);
                visited[i] = 1;
            }
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

    cout << "BFS Traversal: ";

    BFS(0);

    return 0;
}
