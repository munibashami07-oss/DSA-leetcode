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
void 
int main()
{   Node * head = nullptr ; 
    Node * current = nullptr;
    current = head;
    for(int i = 0 ; i <5 ; i++){
        if(head->next==nullptr){
            current->data=i;
            current
        }
    }    
    
    return 0;
}