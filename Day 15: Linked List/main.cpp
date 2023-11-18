#include <iostream>
#include <cstddef>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

    // CHANGE NOTHING ABOVE THIS POINT
      Node* insert(Node *head,int data)
      {
          Node* current = head; // iterator node
          Node* addition = new Node(data); // new node
          
          // place as head if no head
          if (head == NULL)
          {
              head = addition;
          }
          // find end place there
          else 
          {
              Node* current = head;
              
              while (current->next != NULL)
              {
                  current = current->next;
              }
              
              // place as last element's next
              current->next = addition;
          }
          
          // return intial head
          return head;
      }

    // CHANGE NOTHING BELOW THIS POINT

      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);
		
}
