/*

  Improvements
    Single vector for output instead of two
      Swapped out a single for loop with an if-else determine which vector to use
      Now using two for loops, no if, and a single vector for output
    Simplified output loop
      Swapped out two for loops (looping through the 2 output vectors)
      Using a for loop (characters in output vector)

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
        std::vector<char> current;
        char c;

        // get current string
        while (std::cin.get(c) && c != '\n') 
        {
            current.push_back(c);
        }

        // generate output string
        std::vector<char> output;
        for (size_t j = 0; j < current.size(); j += 2) 
        {
            output.push_back(current[j]);
        }

        // seperate even and odd index with a  " "
        output.push_back(' ');

        for (size_t j = 1; j < current.size(); j += 2) 
        {
            output.push_back(current[j]);
        }

        // output each individual character in output string
        for (char characters : output) 
        {
            std::cout << characters;
        }
        std::cout << std::endl;
    }

    return 0;
}
