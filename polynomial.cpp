#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int coefficient;
    int exponent;
    Node* next;
};

// Function to create a new node
Node* createNode(int coefficient, int exponent) {
    Node* newNode = new Node();
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a new term in the polynomial
void insertNode(Node*& head, int coefficient, int exponent) {
    Node* newNode = createNode(coefficient, exponent);

    if (!head || head->exponent < exponent) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next && current->next->exponent > exponent) {
        current = current->next;
    }

    if (current->exponent == exponent) {
        current->coefficient += coefficient;
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the polynomial
void displayPolynomial(Node* head) {
    if (!head) {
        cout << "0";
        return;
    }

    while (head) {
        cout << head->coefficient << "x^" << head->exponent;
        head = head->next;
        if (head) {
            cout << " + ";
        }
    }
    cout << endl;
}

int main() {
    Node* polynomial = nullptr;

    // Inserting terms into the polynomial
    insertNode(polynomial, 3, 4); // 3x^4
    insertNode(polynomial, 5, 2); // 5x^2
    insertNode(polynomial, 6, 3); // 6x^3
    insertNode(polynomial, 1, 0); // 1x^0

    // Displaying the polynomial
    cout << "Polynomial: ";
    displayPolynomial(polynomial);

    return 0;
}lynomial
    insertNode(polynomial, 3, 4); // 3x^4
    insertNode(polynomial, 5, 2); // 5x^2
    insertNode(polynomial, 6, 3); // 6x^3
    insertNode(polynomial, 1, 0); // 1x^0