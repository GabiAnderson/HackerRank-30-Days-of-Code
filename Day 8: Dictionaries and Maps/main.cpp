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
        
        // check if name is in phonebook
        lookupNumber = phonebook[lookupName];
        
        // print output based on result of lookupNumber
        if(lookupNumber == 0)
        {
            cout << "Not found" << endl;
        }
        else
        {
            cout << lookupName << "=" << lookupNumber << endl;
        }
    }
    
    
    return 0;
}
