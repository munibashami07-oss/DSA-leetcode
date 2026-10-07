#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = head;
    head = n;
}

void insertEnd(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    if (head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void search(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            cout << "value us at position " << pos << "\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found\n";
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

int main() {
    int choice, val;
    do {
        cout << "\n1 Insert at Beginning\n2 Insert at End\n3 Display List\n4 Search Element\n5 Delete First Node\n6 Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> val;
                search(val);
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}