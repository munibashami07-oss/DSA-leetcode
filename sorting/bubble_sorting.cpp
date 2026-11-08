#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* nxt;

    Node(int d) {
        data = d;
        nxt = nullptr;
    }
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->nxt;
    }
    cout << "NULL\n";
}

void bubbleSort(Node* head) {

    int comparisons = 0;
    int swaps = 0;

    Node* curr = head;

    // First pass only
    while (curr != nullptr && curr->nxt != nullptr) {

        comparisons++;

        if (curr->data > curr->nxt->data) {

            int temp = curr->data;
            curr->data = curr->nxt->data;
            curr->nxt->data = temp;

            swaps++;

            cout << "After swap " << swaps << ": ";
            printList(head);
        }

        curr = curr->nxt;
    }

    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}
int main(){
 
Node * head ;
Node *n1 = new Node(30);
Node *n2 = new Node (12);
Node * n3 = new Node ( 25);
Node * n4 = new Node (8);
Node * n5 = new Node ( 25);
n1->nxt = n2;
n2->nxt = n3;
n3->nxt = n4; 
n4->nxt = n5;
head = n1;
bubbleSort(head);



}