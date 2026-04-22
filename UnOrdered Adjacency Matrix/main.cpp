#include <iostream>
#include "Stack.h"

using namespace std;

int vertices() {
    cout << "Enter number of vertices: ";
    int n;
    cin >> n;
    return n;
}
void initGraph(bool adj[100][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = false;
        }
    }
}

void addEdges(bool adj[100][100]) {
    int s, d;
    cout << "Enter edge (source destination): ";
    cin >> s >> d;
    adj[s][d] = true;
    adj[d][s] = true;
}
void removeEdges(bool adj[100][100]) {
    int s, d;
    cout << "Enter edge (source destination): ";
    cin >> s >> d;
    adj[s][d] = false;
    adj[d][s] = false;
}

void degrees(bool adj[100][100], int n) {
    int vertex;
    cout << "Enter vertex you want to find degree: ";
    cin >> vertex;
    int degree = 0;
    for(int j = 0; j < n; j++) {
        if(adj[vertex][j]) {
            degree++;
        }
    }
    cout << "Degree of vertex " << vertex << " is: " << degree << endl;
}

bool DFS(bool adj[100][100], int n) {
    int source , destination;
    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Enter destination vertex: ";
    cin >> destination;

    bool visited[100];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }

    Stack st;
    st.push(source);

    while(!st.isEmpty()) {
        int current = st.peek();
        st.pop();
        if(current == destination) {
            return true;
        }
        if(!visited[current]) {
            visited[current] = true;
            for(int i = 0; i < n; i++) {
                if(adj[current][i] && !visited[i]) {
                    st.push(i);
                }
            }
        }
    }
    return false;
}

int main() {
    int n = vertices();
    bool adj[100][100];  // fixed memory (safe)
    initGraph(adj, n);
    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    for(int i = 0; i < e; i++) {
        addEdges(adj);
    }

    addEdges(adj);
    degrees(adj, n);
    cout<<DFS(adj, n);

    return 0;
}
