#ifndef COMMON_H
#define COMMON_H
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
    head = newNode;
}

void display(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

bool search(Node* head, int key)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

void deleteFirst(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Frees every node (avoids memory leaks at program exit)
void freeList(Node*& head)
{
    while (head != NULL)
        deleteFirst(head);
}
#endif
