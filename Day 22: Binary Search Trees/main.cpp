#include <iostream>
#include <cstddef>

using namespace std;    

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution{
    public:
          Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
// DO NOT CHANGE CODE ABOVE
        int getHeight(Node* current){
            // check if tree exists
            if (current == NULL)
            {
                return -1;
            }
            
            // return larger tree + 1 for current node
            return std::max(getHeight(current->left), getHeight(current->right)) + 1;
        }
// DO NOT CHANGE CODE BELOW
}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}
