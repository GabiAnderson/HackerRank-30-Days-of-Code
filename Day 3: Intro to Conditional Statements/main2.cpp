/*

  Changed from 2 if-else blocks to 1 if-else block
    Before:
      Initial check was if n was even or odd, requiring further checks for if n was even and fit the inclusive range conditions
        if (N % 2 == 0)
    After:
      Initial check is if n fits in the "Weird" category entirely, making no required further checks for the "Not Weird" category
        if (N % 2 != 0 || (N >= 6 && N <= 20))

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));
    
    /*
    
    if (N % 2 == 0)
    {
        if ((N >= 2 && N <= 5) || N > 20)
        {
            cout << "Not Weird" << endl;
        }
        else {
            cout << "Weird" << endl;
        }
    }
    else {
        cout << "Weird" << endl;
    }
    
    */
    
    if (N % 2 != 0 || (N >= 6 && N <= 20)) {
        cout << "Weird" << endl;
    } else {
        cout << "Not Weird" << endl;
    }

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
