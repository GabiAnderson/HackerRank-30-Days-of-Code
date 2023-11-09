#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    // read in how many strings there will be
    int count;
    std::cin >> count;
    std::cin.ignore();

    // loop for # of strings
    for(int i = 0; i < count; i++)
    {
        // get all characters in current string
        char c;
        vector<char> current;
        while (std::cin.get(c) && c != '\n') 
        {
            current.push_back(c);
        }  

        // split current string into even index and odd index
        vector<char> s1;
        vector<char> s2;
        for(int j = 0; j < current.size(); j++)
        {
            if(j % 2 == 0)
            {
                s1.push_back(current[j]);
            }   
            else 
            {
                s2.push_back(current[j]);
            }
        }

        // print even index, a space, then odd index
        for(int j = 0; j < s1.size(); j++)
        {
            std::cout << s1[j];
        }
        std::cout << " ";
        for(int j = 0; j < s2.size(); j++)
        {
            std::cout << s2[j];
        }
        std::cout << std::endl;
    }  
    return 0;
}
