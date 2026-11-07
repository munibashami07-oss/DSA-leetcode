
#include <iostream>
using namespace std;

#define SIZE 100

class MinStack {
private:
    int st[SIZE];
    int minSt[SIZE];

    int top;
    int minTop;

public:
    MinStack() {
        top = -1;
        minTop = -1;
    }

    // Push operation
    void push(int value) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow!\n";
            return;
        }

        st[++top] = value;

        if (minTop == -1 || value <= minSt[minTop]) {
            minSt[++minTop] = value;
        }
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return;
        }

        if (st[top] == minSt[minTop]) {
            minTop--;
        }

        cout << "Removed: " << st[top] << endl;
        top--;
    }

    // Get top element
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return -1;
        }

        return st[top];
    }

    // Get minimum element
    int getMin() {
        if (minTop == -1) {
            cout << "Stack is empty!\n";
            return -1;
        }

        return minSt[minTop];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    MinStack s;

    s.push(10);
    s.push(5);
    s.push(20);
    s.push(2);
    s.push(8);

    cout << "Minimum: " << s.getMin() << endl;

    s.pop();

    cout << "Minimum: " << s.getMin() << endl;

    s.pop();

    cout << "Minimum: " << s.getMin() << endl;

    return 0;
}
