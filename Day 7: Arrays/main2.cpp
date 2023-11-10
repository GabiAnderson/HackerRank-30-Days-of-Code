/*

    Modified loop to not handle special case (last element not needing space)
    Before:
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            if(j == 0)
            {
                // if last element include end line
                std::cout << arr[j] << std::endl;
            }
            else 
            {
                // if not last element include space
                std::cout << arr[j] << " ";
            }
        }
    After:
        for (int j = arr.size() - 1; j > 0; j--)
        {
            std::cout << arr[j] << " ";
        }
        std::cout << arr[0] << std::endl;

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }
    
    // loop through array from end to start (end = n-1, start = 0)
    for (int j = arr.size() - 1; j > 0; j--)
    {
        std::cout << arr[j] << " ";
    }
    std::cout << arr[0] << std::endl;

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
