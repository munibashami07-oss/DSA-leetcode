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
    int keys[]={30,12,25,8,20};
   Node * n1 (30);
    Node * head ; 
  head = n1 ; 
  


}