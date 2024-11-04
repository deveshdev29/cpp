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

Node* insert(Node* root, int val){
    if(root == nullptr) return new Node(val);

    if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    return 0;
}