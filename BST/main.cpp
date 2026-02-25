#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node * root= NULL;

Node * insert(Node * curr, int value) {
    if (curr == NULL) {
        Node * temp = new Node();
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        curr= temp;
        return curr;
    }
    if (value < curr->data)
        curr->left = insert(curr->left, value);
    else if (value > curr->data)
        curr->right = insert(curr->right, value);
    return curr;

}

Node *  SearchNode(Node * curr, int value) {

        while (curr != NULL && curr->data != value) {
            if (curr->data < value) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }

    if (curr==NULL) {
        cout<< value<<" NOT FOUND"<<endl;
        return NULL;
    }else if (curr->data == value ) {
            cout << value<< " VALUE FOUND \n";
        return curr ;
    }
}

Node * minValue(Node * curr) {
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node * DeleteNode(Node * curr, int value) {

    // Node * temp = SearchNode(curr, value);
    // Node * holder=temp;
    // if (temp!=NULL) {
    //     if (temp->data == value) {
    //         if (temp->left == NULL && temp->right == NULL) {
    //             delete temp;
    //             temp = NULL;
    //         }else if (temp->left == NULL || temp->right == NULL) {
    //             if (value< temp->data) {
    //                 holder= temp->left;
    //             }else{
    //               holder= temp->right;
    //             }
    //
    //         }
    //     }
    // }

    // Node * prev = curr;
    // Node * temp= curr;
    //
    // while (curr != NULL && curr->data != value) {
    //     if (curr->data < value) {
    //         curr = curr->right;
    //         prev = curr;
    //     }
    //     else {
    //         curr = curr->left;
    //         prev = curr;
    //     }
    // }
    //
    // if (curr->data == value) {
    //     curr = curr->left;
    // }
    //

    if (curr == NULL) {
        return NULL;
    }
    if ( value < curr->data ) {
        curr->left = DeleteNode(curr->left, value);
    }else if (value > curr->data ) {
        curr->right = DeleteNode(curr->right, value);
    }
    else {
        if (curr->left == NULL && curr->right == NULL) {
            delete curr;
           // curr = NULL;
            return NULL;
        }
        if (curr->left == NULL) {
            Node * temp = curr->right;
            delete curr;
            return temp;
        }
        if (curr->right == NULL) {
            Node * temp = curr->left;
            delete curr;
            return temp;
        }
        Node * temp = minValue(curr->right);
        curr->data = temp->data;
        curr->right = DeleteNode(curr->right, temp->data);

    }
return curr;

}

void PreOrderTraversal(Node * curr) {
    if (curr != NULL) {
        cout << curr->data << " ";
        PreOrderTraversal(curr->left);
        PreOrderTraversal(curr->right);
    }
}

void PostOrderTraversal(Node * curr) {
    if (curr != NULL) {
        PostOrderTraversal(curr->left);
        PostOrderTraversal(curr->right);
        cout << curr->data << " ";
    }
}
void InOrderTraversal(Node * curr) {
    if (curr == NULL) {
        return;
    }
        InOrderTraversal(curr->left);
        cout << curr->data << " ";
        InOrderTraversal(curr->right);

}

int main() {

   Node *root_node =  insert(root, 80);
    insert(root_node, 50);
    insert(root_node, 10);
    insert(root_node, 20);
    insert(root_node, 30);
    insert(root_node, 100);
    insert(root_node, 60);

   SearchNode(root_node, 2);
   SearchNode(root_node, 50);

    PreOrderTraversal(root_node);
    cout << endl;
    PostOrderTraversal(root_node);
    cout << endl;
    InOrderTraversal(root_node);
    cout << endl;
    DeleteNode(root_node, 50);
    PreOrderTraversal(root_node);

    return 0;
}