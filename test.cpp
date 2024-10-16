#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int front, rear, size;
    int capacity;

public:
    CircularQueue(int c) {
        capacity = c;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    string enqueue(int x) {
        if (isFull()) {
            return "Queue is full";
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = x;
        size++;
        return "Enqueued " + to_string(x);
    }

    string dequeue() {
        if (isEmpty()) {
            return "Queue is empty";
        }
        string result = "Dequeued " + to_string(queue[front]);
        front = (front + 1) % capacity;
        size--;
        if (size == 0) {
            front = -1;
            rear = -1;
        }
        return result;
    }

    string frontElement() {
        if (isEmpty()) {
            return "Queue is empty";
        } else {
            return "Front element: " + to_string(queue[front]);
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    int capacity, num_operations;
    cin >> capacity >> num_operations;

    CircularQueue q(capacity);
    vector<string> results;

    for (int i = 0; i < num_operations; i++) {
        string operation;
        cin >> operation;

        if (operation == "enqueue") {
            int x;
            cin >> x;
            results.push_back(q.enqueue(x));
        } else if (operation == "dequeue") {
            results.push_back(q.dequeue());
        } else if (operation == "front") {
            results.push_back(q.frontElement());
        } else if (operation == "isEmpty") {
            results.push_back(q.isEmpty() ? "true" : "false");
        } else if (operation == "isFull") {
            results.push_back(q.isFull() ? "true" : "false");
        }
    }
larQueue
    for (const string &result : results) {
        cout << result << endl;
    }

    return 0;
}
