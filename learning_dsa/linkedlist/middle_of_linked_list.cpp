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
        for (int n = 1 ; n<count ; n++) 
        {
            current = current->next ;
        }
         cout<<"Middle nodes are "<<count<<"\t"<<current->word<<"\n";
         current = current->next ;
         cout<<"Middle nodes are "<<count+1<<"\t"<<current->word<<endl;

        }
        else{ count = count/2;
       
        for (int n = 0; n<count ; n++) //0 1
        {
            current = current->next; //2 3
        }
         cout<<"Middle node is"<<count+1<<"\t"<<current->word;
        }
    }}

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