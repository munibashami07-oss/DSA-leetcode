#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class Node{
    public : 
    string word;
    Node *next;
    Node(string w = ""){
        word = w;
        next = nullptr;
    }
};
class Linkedlist {
    Node* head;
    public:
    Linkedlist(){ head = nullptr; } //assigning head

    void insert(string w){
        Node* newNode = new Node(w);
        if(head == nullptr){
            head=newNode ; 
            return;
        }
        Node *curr = head;
        while(curr->next != nullptr ){
            curr=curr->next;
        }
        curr->next =newNode;
    }

    //reverse the linked list
   Node* reverse(){
        Node  *prev = nullptr;
        Node * curr = head;
        while (curr != nullptr){
            Node* nxt = curr->next;
            curr->next=prev;
            prev= curr ; 
            curr = nxt;
        }
        head = prev ; 
        return prev;
   }

   void display (){
    for (Node * curr  = head ; curr != nullptr ; curr  = curr -> next){
        cout << curr->word << "->";
    }
    cout<<"Null"<<endl;
   }
};

int main()
{ Linkedlist list;
    list.insert("1");
    list.insert("2");
    list.insert("3");
    list.insert("4");
 list.display();
 list.reverse();
 list.display();
    

    return 0;
}
// Weak Spot Radar
// Seeing the arrows: people picture the nodes moving, but only the pointers change.
// Losing the tail of the list: the usual bug is overwriting next before saving it.
// Mixing up the returns: you return prev, not curr or head.
// Recursion: most people can write it but can't explain the unwinding order.
// Trusting the invariant: if you can't state what prev and curr represent at every iteration, you're memorizing, not understanding.