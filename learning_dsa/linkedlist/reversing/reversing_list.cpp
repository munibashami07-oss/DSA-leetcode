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
   void reverse(){
        Node  *prev = nullptr;
        Node * curr = head;
        while (curr != nullptr){
            Node* nxt = curr->next;
            curr->next=prev;
            prev= curr ; 
            curr = nxt;
        }
        head = prev ; 
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