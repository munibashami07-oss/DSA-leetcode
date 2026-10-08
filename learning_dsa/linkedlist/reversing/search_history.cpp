// 3. Your Challenge

// Your autocomplete stores search history oldest to newest in a linked list. Write showRecent(Node*& head, int k) that:

// Prints the k most recent searches, newest first.
// Uses no array, vector or stack.
// Leaves the list in its original order afterwards.
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string word;
    Node* next;

    Node(string w) {
        word = w;
        next = nullptr;
    }
};

// Reverse the linked list
void reverse(Node*& head) {
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

// Show k most recent searches
void showRecent(Node*& head, int k) {

    // Reverse the list
    reverse(head);

    // Print k most recent searches
    Node* current = head;

    int count = 0;

    cout << "\nMost Recent Searches:\n";

    while (current != nullptr && count < k) {
        cout << current->word << endl;

        current = current->next;
        count++;
    }

    // Restore original order
    reverse(head);
}

int main() {

    Node* head = nullptr;
    Node* tail = nullptr;

    int n;

    cout << "How many searches do you want to enter? ";
    cin >> n;

    cin.ignore();

    // Take search history from user
    for (int i = 0; i < n; i++) {

        string search;

        cout << "Enter search " << i + 1 << ": ";
        getline(cin, search);

        Node* newNode = new Node(search);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;

    cout << "\nHow many recent searches do you want to see? ";
    cin >> k;

    showRecent(head, k);

    // Check that original list is still unchanged
    cout << "\nOriginal Search History:\n";

    Node* current = head;

    while (current != nullptr) {
        cout << current->word << " -> ";
        current = current->next;
    }

    cout << "NULL\n";

    return 0;
}