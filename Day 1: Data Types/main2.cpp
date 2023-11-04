/*

  Changed from 2 lines of std::cin to read int and double into 1 line
    Before:
      std::cin >> i2;
      std::cin >> d2;
    After:
      std::cin >> i2 >> d2;
  Simplified cin.ignore
    Before:
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    After:
      cin.ignore();

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
    std::cin >> i2 >> d2;
    // ignore the newline character from input stream that causes issues with strings
    cin.ignore();
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
