#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic{
    public:
        virtual int divisorSum(int n)=0;
};
// DO NOT CHANGE CODE ABOVE

class Calculator : public AdvancedArithmetic {
public:
    int divisorSum(int n) {
        vector<int> divisors;
        
        // decrease from n until 0 - check if proper divisor
        for(int i = n; i > 0; i--)
        {
            if(n % i == 0)
            {
                divisors.push_back(i);
            }
        }
        
        int sum{};
        
        // sum divisors
        for(int j = 0; j < divisors.size(); j++)
        {
           sum += divisors[j]; 
        }
        
        return sum;
    }
};

// DO NOT CHANGE CODE BELOW
int main(){
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator(); 
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}
