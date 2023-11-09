/*

  Improvements(?)
    To get even more practice I took main2.cpp and converted from vector<char> to strings (kind of the same thing but different handling in some cases)

*/

#include <iostream>
#include <vector>

int main() 
{
    // determine how many strings there will be
    int count;
    std::cin >> count;
    std::cin.ignore();

    // loop through number of strings
    for (int i = 0; i < count; i++) 
    {
        // get current
        std::string current;
        std::getline(std::cin, current);
        
        // pull even index
        std::string output;
        for(int j = 0; j < current.size(); j += 2)
        {
            output += current[j];
        }
        
        // seperate even and odd index
        output += " ";
        
        // put odd index
        for(int k = 1; k < current.size(); k += 2)
        {
            output += current[k];
        }
        
        // return output
        std::cout << output << std::endl;
    }

    return 0;
}
