#include <iostream>
#include <iomanip>
using namespace std;
class Node{
    public : 
    int data ;
    Node * next ;
    Node ( int value){
        data = value ; 
        next = nullptr;
    }
};
int main()
{
    Node * head = nullptr; 
    Node * curr = nullptr ; 
    Node * n1 = new Node(1);
    head = n1;
     Node * n2 = new Node(2);
      Node * n3 = new Node(3);
       Node * n4 = new Node(4);
        Node * n5 = new Node(5);

        n1->next = n2;
         n2->next = n3;
         n3->next = n4;
         n4->next = n5;
         n5->next = head;

cout<<n1->data<<"->"<<n1->next->data<<"->"<<n1->next->next->data<<"->"<<n1->next->next->next->data<<"->"<<n1->next->next->next->next->data<<"->"<<n1->next->next->next->next->next->data<<endl;

}