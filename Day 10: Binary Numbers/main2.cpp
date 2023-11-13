/*

    Improved performance by dynamically counting bits aka remvoing unneccsarry bits to help with storage and iteration later on
        Before:
            string binary = bitset<32>(n).to_string();
        After:
            int significantBits = log2(n) + 1;
            string binary = bitset<32>(n).to_string().substr(32 - significantBits);
    Utilized functions to reduce code length and look
        Before:
            if(count > max)
            {
                max = count;
            }
        After:
            max = std::max(count, max);
*/

#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    // determine the number of significant bits in the binary representation
    int significantBits = log2(n) + 1;

    // convert base 10 string into a binary string representation
    string binary = bitset<32>(n).to_string().substr(32 - significantBits);

    // initialize max and current count (of 1's in binary string) to 0
    int count = 0;
    int max = 0;

    // loop through every bit in the binary string
    for (char bit : binary)
    {
        // if the current bit is a '1', increment the current count
        if (bit == '1')
        {
            count++;
        }
        else
        {
            // check if count > max and update max
            max = std::max(count, max);

            // reset count
            count = 0;
        }
    }

    // final check if count > max
    max = std::max(count, max);

    // display max (biggest grouping of 1's)
    cout << max << endl;

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
