#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
// DO NOT CHANGE CODE ABOVE
          Node* removeDuplicates(Node *head)
          {
              Node* iterator1;
              Node* iterator2;
              Node* copy;
              
              iterator1 = head;
              
              // loop through list
              while(iterator1 != NULL && iterator1->next != NULL)
              {
                  iterator2 = iterator1;
                  
                  // loop through remainder of list
                  while(iterator2->next != NULL)
                  {
                      // check for duplicate
                      if(iterator1->data == iterator2->next->data)
                      {
                          copy = iterator2->next;
                          // update links
                          iterator2->next = iterator2->next->next;
                          // remove from mem
                          delete (copy); 
                      }
                      else // no duplicate so move to next 
                      {
                          iterator2 = iterator2->next;
                      }
                  }
                  
                  // move to next
                  iterator1 = iterator1->next;
              }
            
            return head;
          }
// DO NOT CHANGE CODE BELOW
          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;  

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;   

               }
                    return head;
                
            
          }
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
    head=mylist.removeDuplicates(head);

	mylist.display(head);
		
}
