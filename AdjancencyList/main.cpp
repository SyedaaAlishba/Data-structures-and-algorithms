#include <iostream>
#include <vector>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int vertices() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    return n;
}

void addEdges(vector<int> adj[]) {
    int s, d;
    cout << "Enter edge (source destination): ";
    cin >> s >> d;
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void degrees(vector<int> adj[], int n) {
    int vertex;
    cout << "Enter vertex: ";
    cin >> vertex;

    cout << "Degree: " << adj[vertex].size() << endl;
}

bool DFS(vector<int> adj[], int n) {
    int source, destination;
    cout << "Enter source: ";
    cin >> source;
    cout << "Enter destination: ";
    cin >> destination;

    bool visited[100] = {false};

    Stack st;
    st.push(source);

    while(!st.isEmpty()) {
        int current = st.peek();
        st.pop();

        if(current == destination)
            return true;

        if(!visited[current]) {
            visited[current] = true;

            for(int i = 0; i < adj[current].size(); i++) {
                int neighbor = adj[current][i];
                if(!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
    return false;
}
bool BFS(vector<int> adj[], int n) {
    int source, destination;
    cin >> source >> destination;

    bool visited[100] = {false};

    Queue q;
    q.Enqueue(source);
    visited[source] = true;

    while(!q.isEmpty()) {
        int current = q.Dequeue();

        if(current == destination)
            return true;

        for(int i = 0; i < adj[current].size(); i++) {
            int neighbor = adj[current][i];

            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.Enqueue(neighbor);
            }
        }
    }
    return false;
}
int main() {
    int n = vertices();
    vector<int> adj[100];

    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    for(int i = 0; i < e; i++) {
        addEdges(adj);
    }

    degrees(adj, n);
    cout << DFS(adj, n);
    cout<< BFS(adj, n);

    return 0;
}