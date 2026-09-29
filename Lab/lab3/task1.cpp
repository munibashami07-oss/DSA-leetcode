// Task 1: Create a singly linked list containing 5 nodes.
#include "common.h"

int main()
{
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Linked list with 5 nodes:" << endl;
    display(head);

    freeList(head);
    return 0;
}
