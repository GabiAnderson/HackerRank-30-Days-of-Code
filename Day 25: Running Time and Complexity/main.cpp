#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // get number of test cases 
    int testCases{};
    cin >> testCases;
    //cout << "Test Cases: " << testCases << endl;
    
    // loop through test cases
    for(int i = 0; i < testCases; i++)
    {
        // get number to test or current
        int num{};
        cin >> num;
        bool prime = true;
        //cout << "Number: " << num << endl;
        
        if (num <= 1) 
        {
            prime = false; // 0 and 1 are not prime numbers
        } 
        else 
        {
            // loop from 2 to sqrt(num)
            //      if num has any divisors they will fall within the range of 2 to sqrt(num) without
            //      encountering duplicates or excess - aka we can reduce our loop range to prevent
            //      excessive checks
            for (int j = 2; j <= std::sqrt(num); j++) 
            {
                if (num % j == 0) 
                {
                    prime = false;
                    break;
                }
            }
        }
        
        // use bool to return result
        if (prime)
        {
            cout << "Prime" << endl;
        }
        else 
        {
            cout << "Not prime" << endl;
        }
    }
    return 0;
}
