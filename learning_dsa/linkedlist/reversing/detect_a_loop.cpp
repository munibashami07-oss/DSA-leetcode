#include <iostream>
#include <iomanip>
using namespace std;
class Node{
    public : 
    int data ; 
    Node * next;
    Node(int d)
    {
        data = d ;
        next = nullptr;
    }
};
bool loopdetect(Node * & head){
Node * fast = head;
Node * slow = head;
Node * current = head;
while ( fast!=nullptr && fast ->next !=nullptr)
{
    fast=current->next->next;
    slow= current->next;
    if(fast==slow){
        return 1;
    }
    current=current->next;
}
current = current->next;
} 
int main()
{   Node * head = nullptr ; 
    Node * current = nullptr;
    current = head;
    // create nodes
    for(int i = 0 ; i <5 ; i++){
      current->next= new Node(i);
      current = current->next ; 
    }    

    if(loopdetect(head)){
        cout<<"Loop is detected\n";
    }
    else {
          cout<<"Loop is not detected\n";
    }
//creating loop in the nodes now 
current -> next  = head->next;
   if(loopdetect(head)){
        cout<<"Loop is detected";
    }
    else {
          cout<<"Loop is not detected";
    }
    
    
    return 0;
}