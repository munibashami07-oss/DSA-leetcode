#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void insertAtBeginning(Node*& head, int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;}

void display(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

int countNodes(Node* head)
{
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

bool insertAfter(Node* head, int target, int newValue)
{
    Node* current = head;
    while (current != NULL && current->data != target)
        current = current->next;

    if (current == NULL)
        return false;               // target not found

    Node* newNode = new Node();
    newNode->data = newValue;
    newNode->next = current->next;  // link new node to the rest
    current->next = newNode;        // link target to new node
    return true;
}

void deleteLast(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL)         // forone node
    {
        delete head;
        head = NULL;
        return;
    }
    Node* current = head;
    while (current->next->next != NULL)  //2nd kast node
        current = current->next;

    delete current->next;
    current->next = NULL;
}

// Frees every node....avoids memory leaks at program exit
void freeList(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    while (head != NULL)
       { 
    Node* temp = head;
    head = head->next;
    delete temp; }
}

int main()
{
    Node* head = NULL;

    cout << "Empty list -> node count: " << countNodes(head) << endl;
 cout<<"-----------------------------------"<<endl;

 //task1 Create a singly linked list containing 5 nodes
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    cout << "Linked list with 5 nodes:" << endl;
    display(head);

// task2  Write a function to count the number of nodes
     cout<<"-----------------------------------"<<endl;

    cout << "Number of nodes: " << countNodes(head) << endl; 

//task3  Write a function to insert a node after a given value.
 cout<<"-----------------------------------"<<endl;
if (insertAfter(head, 2, 6))
        cout << "\nInserted 6 after 2:" << endl;
    display(head);

//task4 Write a function to delete the last node
 cout<<"-----------------------------------"<<endl;
    deleteLast(head);
    cout << "\nAfter deleting last node:" << endl;
    display(head);

    freeList(head);
    return 0;
}
