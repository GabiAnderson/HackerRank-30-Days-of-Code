#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }
// DO NOT CHANGE CODE ABOVE
	void levelOrder(Node * root){
        // check tree exists
        if (root == NULL)
            return;
    
        // queue used for traversal
        queue<Node*> q;
    
        // begin traversal with root
        q.push(root);
    
        while (q.empty() == false) 
        {    
            // display q front and remove it
            Node* node = q.front();
            cout << node->data << " ";
            q.pop();
    
            // add left child
            if (node->left != NULL)
            {
                //cout << "Left child: " << node->left->data << endl;
                q.push(node->left);
            }
    
            // add right child
            if (node->right != NULL)
            {
                //cout << "Right child: " << node->right->data << endl;
                q.push(node->right);
            }
        }
	}
// DO NOT CHANGE CODE BELOW
};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}
