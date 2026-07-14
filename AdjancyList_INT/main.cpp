#include <iostream>
using namespace std;
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
void displayGraph()
{
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