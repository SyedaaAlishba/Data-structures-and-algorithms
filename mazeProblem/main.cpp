#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
using namespace std;
int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};

int parent[1000];

struct Node
{
    int data;
    Node* next;
};

struct Vertex
{
    int data;
    Vertex* next;
    Node* adjList;
};

Vertex* head=NULL;

void addVertex(int v)
{
    Vertex* newNode=new Vertex();

    newNode->data=v;
    newNode->next=NULL;
    newNode->adjList=NULL;

    if(head==NULL)
    {
        head=newNode;
        return;
    }

    Vertex* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
}
Vertex* findVertex(int v)
{
    Vertex* temp=head;

    while(temp!=NULL)
    {
        if(temp->data==v)
            return temp;

        temp=temp->next;
    }

    return NULL;
}
void addEdge(int from,int to)
{
    Vertex* v=findVertex(from);

    if(v==NULL)
        return;

    Node* newNode=new Node();

    newNode->data=to;
    newNode->next=NULL;

    if(v->adjList==NULL)
    {
        v->adjList=newNode;
        return;
    }

    Node* temp=v->adjList;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
}
void displayGraph() {
    Vertex* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";

        Node* adj=temp->adjList;

        while(adj!=NULL)
        {
            cout<<adj->data<<" ";

            adj=adj->next;
        }

        cout<<endl;

        temp=temp->next;
    }
}

void generateMaze(int maze[][100], int n, int m)
{
    srand(time(0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            maze[i][j]=rand()%2;
        }
    }

    // Start and End should always be open

    maze[0][0]=0;
    maze[n-1][m-1]=0;
}

void displayMaze(int maze[][100], int n, int m)
{
    cout << "\nMaze:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}
void buildVertices(int maze[][100], int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maze[i][j]==0)
            {
                int id=i*m+j;

                addVertex(id);
            }
        }
    }
}

void buildEdges(int maze[][100], int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            // Wall hai to skip
            if(maze[i][j]==1)
                continue;

            int u=i*m+j;

            // Check all 8 neighbours
            for(int k=0;k<8;k++)
            {
                int newRow=i+dr[k];
                int newCol=j+dc[k];

                // Check bounds
                if(newRow>=0 && newRow<n &&
                   newCol>=0 && newCol<m)
                {
                    // Neighbour bhi open hona chahiye
                    if(maze[newRow][newCol]==0)
                    {
                        int v=newRow*m+newCol;

                        addEdge(u,v);
                    }
                }
            }
        }
    }
}

void printPath(int destination, int m)
{
    int path[1000];
    int count = 0;

    int current = destination;

    while(current != -1)
    {
        path[count++] = current;
        current = parent[current];
    }

    cout << "\nPath:\n";

    for(int i = count - 1; i >= 0; i--)
    {
        cout << "(" << path[i] / m << "," << path[i] % m << ")";

        if(i != 0)
            cout << " -> ";
    }

    cout << endl;
}
bool BFS(int start,int destination,int m) {
    bool visited[1000];


    for(int i=0;i<1000;i++){
        visited[i]=false;
    parent[i]=-1;
}

    queue<int> q;

    q.push(start);
    visited[start]=true;

    while(!q.empty())
    {
        int current=q.front();
        q.pop();

        if(current==destination)
        {
            printPath(destination,m);

            return true;
        }

        Vertex* v=findVertex(current);
        if(v==NULL)
            continue;
        Node* temp=v->adjList;

        while(temp!=NULL)
        {
            int neighbour=temp->data;

            if(!visited[neighbour])
            {
                visited[neighbour]=true;

                parent[neighbour]=current;

                q.push(neighbour);
            }

            temp=temp->next;
        }
    }

    return false;
}
int main() {
    int n,m;

    cin>>n>>m;

    int maze[100][100];

    generateMaze(maze,n,m);

    displayMaze(maze,n,m);

    buildVertices(maze,n,m);

    buildEdges(maze,n,m);

    displayGraph();

    int start = 0;
    int destination = (n-1)*m + (m-1);

    if(!BFS(start,destination,m))
    {
        cout<<"No Path Exists";
    }
    return 0;
}