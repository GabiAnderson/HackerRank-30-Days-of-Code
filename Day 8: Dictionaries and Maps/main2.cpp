/*

  Functionality and concepts are the same. Utilized a map's .find method instead of attemtping to access a name that may not exist.

  The length of the code is the same but it gave me some practice with .find

  I was using the results of a direct access to determine if the name was in the phonebook.
  Before:
    lookupNumber = phonebook[lookupName];

  Now I am using the results .find to determine if the whole phonebook was checked for the name
  After:
    auto it = phonebook.find(lookupName);

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    // get number of entries
    int count;
    cin >> count;
    cin.ignore();
    
    map<string, int> phonebook;
    
    // collect entries
    for(int i = 0; i < count; i++)
    {
        string name;
        int number;
        
        cin >> name >> number;
        
        //cout << name << " " << number << endl;
        
        // fill phonebook
        phonebook[name] = number;
    }
    
    // loop through queries
    string lookupName;
    int lookupNumber;
    while(cin >> lookupName)
    {
        // cout << lookupName << endl;
        //cout << phonebook["john"] << endl;
        
        // use find to check if the name exists
        auto lookupNumber = phonebook.find(lookupName);

        if (lookupNumber != phonebook.end()) {
            // Name found
            cout << lookupName << "=" << lookupNumber->second << endl;
        } 
        else 
        {
            // Name not found
            cout << "Not found" << endl;
        }
    }
    
    
    return 0;
}
