#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;



int main()
{
    string S;
    getline(cin, S);
    
    // set holder var
    int val{};
    
    // attempt to convert and print var
    try 
    {
        val = stoi(S);
        cout << val << endl;
    } 
    // catch a bad conversion
    catch (std::invalid_argument) 
    {
        cout << "Bad String" << endl;
    }

    return 0;
}
