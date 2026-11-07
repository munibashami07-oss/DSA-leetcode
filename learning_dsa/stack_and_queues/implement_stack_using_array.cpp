#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
private:
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Insert element
    void push(int value) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow!\n";
            return;
        }

        top++;
        arr[top] = value;
    }

    // Remove element
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return;
        }

        cout << "Removed: " << arr[top] << endl;
        top--;
    }

    // Return top element
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return -1;
        }

        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top: " << s.peek() << endl;

    s.pop();

    s.display();

    return 0;
}
