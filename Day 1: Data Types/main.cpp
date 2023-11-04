/*

  Day 1 Task: Declare variables of different data types, read and save different data types to declared variables, print sums/concatenations 

  Issues:
    - Only issue encountered today stems from std::cin holding a \n in the input stream after reading my int/double which resulted in my string not filling properly. A small cin.ignore fixed the issue

*/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int i2;
    double d2;
    string s2 = "";
    
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    std::cin >> i2;
    std::cin >> d2;
    // ignore the newline character from input stream that causes issues with strings
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::getline(std::cin, s2);
    
    
    // Print the sum of both integer variables on a new line.
    std::cout << i + i2 << std::endl;
    
    // Print the sum of the double variables on a new line.
    std::cout << std::fixed << std::setprecision(1) << d + d2 << std::endl;
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    std::cout << s + s2 << std::endl;

    return 0;
}
