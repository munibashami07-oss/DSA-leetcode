#include <iostream>
using namespace std;
class Node
{
public:
int data;
Node* next;
Node(int value)
{ data = value;
next = NULL;
}
};
class LinkedList
{
private:
Node* head;
int  i =0 ;

void splitList(Node* source, Node*& left, Node*& right)
{
    i++;
Node* slow = source;
Node* fast = source->next;
while (fast!= NULL)
{
fast = fast->next;
if(fast != NULL)
{
slow = slow->next;
fast = fast->next;
}
}
left = source;
right = slow->next;
slow->next = NULL;
cout<<"run "<<i<<"split list node is "<<left->data<<" and "<<right->data<<endl;
}
Node* mergeSortedLists(Node* left, Node* right)
{ if(left == NULL)
return right;
if(right == NULL)
return left;
Node* result = NULL; 
if(left->data <= right->data)
{
result = left;
result->next = mergeSortedLists(left->next, right);
cout<<"now list is  "<<result->next->data<<endl;
}
else
{ result = right;
result->next = mergeSortedLists(left, right->next);
cout<<"now list is  "<<result->next->data<<endl;
}
return result;
}
Node* mergeSortRec(Node* start)
{
if(start == NULL || start->next == NULL)
return start;
Node* left = NULL;
Node* right = NULL;
splitList(start, left, right);
left = mergeSortRec(left);
right = mergeSortRec(right);
cout<<"at mergesortrec "<<left->data<<" "<<right->data<<endl;
return mergeSortedLists(right, left);
}
public:
LinkedList()
{
head = NULL;
}
void insertAtEnd(int value)
{
Node* newNode = new Node(value);
if(head == NULL)
{
head = newNode;
return;
}
Node* temp = head;
while(temp->next != NULL)
{
temp = temp->next;
}
temp->next = newNode;
} 
void display()
{
Node* temp = head;
while(temp != NULL)
{
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
}
void mergeSort()
{
head = mergeSortRec(head);
}
};
int main()
{
LinkedList list;

int n , val; 
cout<<"enter number of values\n";
cin>>n;
for (int i = 0 ; i < n ; i++)
{
    cout<<"enyer value : ";
    cin>>val;
    list.insertAtEnd(val);
    cout<<endl;
}
cout << "Original List: ";
list.display();
list.mergeSort();
cout << "Sorted List: ";
list.display();
return 0;
} 