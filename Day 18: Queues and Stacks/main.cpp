#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
    //Write your code here
    public:
        // create stack and queue instances
        stack<char> myStack;
        queue<char> myQueue;
        
        // push character to top of stack
        void pushCharacter(char ch)
        {
            myStack.push(ch);
        }
        
        // pop character from top of stack
        char popCharacter()
        {
            // get current top element
            char ret = myStack.top();
            // pop off top element
            myStack.pop();
            // return popped off element
            return ret;
        }
        
        // push character into queue
        void enqueueCharacter(char ch)
        {
            myQueue.push(ch);
        }
        
        // pop character out of queueu
        char dequeueCharacter()
        {
            // get current front element
            char ret = myQueue.front();
            // pop off front element
            myQueue.pop();
            // return popped off element
            return ret;
        }
};

// DO NOT CHANGE CODE BELOW

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
      // create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}
