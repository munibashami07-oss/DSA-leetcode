#include <iostream>
#include <iomanip>
using namespace std;
class Node{
    public:
    string word;
    Node * next ; 
    Node(string w){
        word=w;
        next = nullptr;
    }};


int main()
{
    Node * head ;
    Node * curr ;
    string word; 
    int count =0;
    cout<< " Enter the nodes (to exit press 0 ) : "<<endl;
    for(int i = 0 ;   ; i++)
    {
        getline(cin,word);
        if (word=="0")
        {
            break;
        }
        Node * newNode = new Node(word);
        if(head == nullptr){
            head = newNode;
            curr  = newNode;
        }
        else{
            curr->next=newNode;
            curr=newNode;
        }
        count++;
    }
    cout<<count;
    return 0;
}