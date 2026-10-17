
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = nullptr;
    }

    // Push: Insert an element at the top
    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack." << endl;
    }

    // Pop: Remove the top element
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped from stack." << endl;
        top = top->next;
        delete temp;
    }

    // Peek: Display the top element
    void peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element: " << top->data << endl;
    }

    // Display all elements
    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = top;

        cout << "Stack (Top to Bottom): ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Check whether the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Count the number of elements
    int size()
    {
        int count = 0;
        Node* current = top;

        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        return count;
    }

    // Destructor: Free all allocated memory
    ~Stack()
    {
        while (top != nullptr)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Stack s;

    cout << "--- PUSH 10 ELEMENTS ---" << endl;

    for (int i = 10; i <= 100; i += 10)
    {
        s.push(i);
    }

    cout << "\n--- DISPLAY STACK ---" << endl;
    s.display();

    cout << "\n--- PEEK OPERATION ---" << endl;
    s.peek();

    cout << "\n--- SIZE OPERATION ---" << endl;
    cout << "Number of elements: " << s.size() << endl;

    cout << "\n--- IS EMPTY OPERATION ---" << endl;
    cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;

    cout << "\n--- POP OPERATION ---" << endl;
    s.pop();

    cout << "\n--- DISPLAY AFTER POP ---" << endl;
    s.display();

    cout << "\n--- PUSH ANOTHER ELEMENT ---" << endl;
    s.push(110);
    s.display();

    cout << "\n--- FINAL SIZE ---" << endl;
    cout << "Number of elements: " << s.size() << endl;

    return 0;
}
