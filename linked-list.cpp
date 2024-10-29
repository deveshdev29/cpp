#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

void insertAtBeginning(Node*& head, int value){
    Node* newnode = new Node(value);
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(Node*& head, int value){
    Node* newnode = new Node(value);

    if(!head){
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newnode;

}

void deleteNode(Node*& head, int key){
    if(!head) return;
    if(head->data == key){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while(temp->next && temp->next->data != key){
        temp = temp->next;
    }

    if(temp->next){
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

void printList(Node*& head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = nullptr;

    insertAtBeginning(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtBeginning(head, 0);

    printList(head);

    deleteNode(head, 2);
    printList(head);
    return 0;
}