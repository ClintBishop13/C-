#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* Create(int data)
{
    Node* tmp = new Node();
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
    
}

void Insert(Node* &root, int data)
{
    if(root == NULL)
        root = Create(data);
    else if (root->data > data)
        Insert(root->left, data);
    else
        Insert(root->right, data);
}

void DisplayTreeInPreorder(Node* root)
{
    if(root != NULL)
    {
        cout << root->data << endl;
        DisplayTreeInPreorder(root->left);
        DisplayTreeInPreorder(root->right);
    }
}

void DisplayTreeInorder(Node* root)
{
    if(root != NULL)
    {
        DisplayTreeInorder(root->left);
        cout << root->data << endl;
        DisplayTreeInorder(root->right);
    }
}

void DisplayTreePostorder(Node* root)
{
    if(root != NULL)
    {
        DisplayTreePostorder(root->left);
        DisplayTreePostorder(root->right);
        cout << root->data << endl;
    }
}

int main(){

    Node* root = NULL;
    Insert(root, 1);
    Insert(root->left, 2);
    Insert(root->right, 3);
    Insert(root->left->left, 4);
    Insert(root->left->right, 5);
    Insert(root->left->right->right, 7);
    Insert(root->right->left, 8);
    Insert(root->right->right, 10);
    Insert(root->right->right->right, 12);
    Insert(root->right->right->right->right, 14);
    Insert(root->right->right->right->right->left, 15);
    Insert(root->right->right->right->right->right, 16);
    Insert(root->right->right->right->right->left->left, 17);
    DisplayTreeInPreorder(root);

} 
