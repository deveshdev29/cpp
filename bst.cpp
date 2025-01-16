#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value){
    if(root == nullptr){
        return new Node(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    }else{
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(Node* root){
    if(root != nullptr){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main(){
    Node* root = nullptr;
    
    int n, value;
    cout << "Enter the number of Nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for(int i = 0; i < n; i++){
        cin >> value;
        root = insert(root, value);
    }

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;
    return 0;
}