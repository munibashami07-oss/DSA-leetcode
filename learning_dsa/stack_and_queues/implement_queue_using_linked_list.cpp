#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Insert at rear
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (front == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Remove from front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Removed: " << temp->data << endl;

        front = front->next;

        // If queue becomes empty
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Return front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return -1;
        }

        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* current = front;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    // Destructor
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front: " << q.peek() << endl;

    q.dequeue();

    q.display();

    return 0;
}
