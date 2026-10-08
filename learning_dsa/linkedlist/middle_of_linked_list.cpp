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
void FindMiddle(Node*& head , int count ){
    if(count == 0 || count == 1 || count == 2){
        cout<<"theres no middle";
    }
    else{
         Node * current = head;

        if(count%2==0){
count = count/2;

        }
        else{ count = count/2;
        count=count+1;    
cout<<count;
        
        }

       

    }

}

int main()
{
    Node * head = nullptr ; //initialize them or the loop wont  run 
    Node * curr = nullptr ; //initialize them or the loop wont  run 
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
    FindMiddle(head , count);
    return 0;
}