// create a  stack of atleast 10 elements using linked list and write function of all the relevant  
// operations of a stack . write a code to demostrate the functioning of all of the operations and record  output 
#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public : 
int data ;
Node * next;
Node(int val){
data = val; 
next = nullptr ; 
}

};

class Stack {
public :
Node *top ; 
Stack (){
    top = nullptr ; 
}
~Stack()
    {
        while (top != nullptr)
        {
            Node* curr = top;
            top = top->next;
            delete curr;
        }
    }
//to insert  (push )
void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
//to pop 
void pop(){
   if (top == nullptr)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* curr = top;
        cout << curr->data << " popped " << endl;
        top = top->next;
        delete curr;
}
 //peek
    void peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element: " << top->data << endl;
    }

//displayinggg all elements 
void display(){
    if(top==nullptr)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        Node * curr = top ; 
        while (curr -> next != nullptr ){
            cout<<curr->data<<endl;
             cout<<"|"<<endl;
              cout<<"v"<<endl;
              curr= curr->next ; 
        }
    cout<<curr->data<<endl;
}
bool emptycheck(){
    if(top==nullptr){
        return 0;
    }
    else{
        return 1;
    }
}
//count 
int count()
    {
        int count = 0;
        Node* current = top;

        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        return count;
    }
       // free memory
    
};
int main()
{ Stack s;
Stack d;
    for (int i = 1; i <= 10; i ++)
    {
        s.push(i);
    }
  s.display();
   s.peek();

    cout << "no. of elements " << s.count() << endl;

    
    cout << (s.emptycheck() ?  "empty stack " : "not empty.") << endl;
    s.pop();
    s.display();
    return 0;
}