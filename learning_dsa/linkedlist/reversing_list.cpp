#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string word;
    Node* next;

    // Constructor
    Node(string w) {
        word = w;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Add a node at the end
    void insert(string word) {
        Node* newNode = new Node(word);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* nxt = current->next;

            current->next = prev;

            prev = current;
            current = nxt;
        }

        head = prev;
    }

    // Display the linked list
    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->word << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {

    LinkedList list;

    list.insert("Hello");
    list.insert("World");
    list.insert("DSA");
    list.insert("C++");

    cout << "Original List:" << endl;
    list.display();

    list.reverse();

    cout << "\nReversed List:" << endl;
    list.display();

    return 0;
}