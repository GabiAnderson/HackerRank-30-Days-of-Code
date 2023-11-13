#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    
    // convert base 10 string into a binary string representation
    string binary = bitset<32>(n).to_string();
    
    // initialize max and current count (of 1's in binary string) to 0
    int count{};
    int max{};
    
    // loop through every bit in the binary string
    for(char bit : binary)
    {
        // if current bit is a 1 increment the current count
        if(bit == '1')
        {
            count++;
        }
        else 
        {
            // check if count > max and update max
            if(count > max)
            {
                max = count;
            }
            
            // reset count
            count = 0;
        }
    }
    
    // final check if count > max
    if(count > max)
    {
        max = count;
    }
    
    // display max (biggest grouping of 1's)
    cout << max << endl;

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
