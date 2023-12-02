#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bitwiseAnd' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER K
 */

int bitwiseAnd(int N, int K) {
    //cout << "N: " << N << endl;
    int max{};
    
    // loop through set
    for(int i = 1; i <= N; i++)
    {
        //cout << i << endl;
        
        // loop through remainder of set
        for(int j = i+1; j <= N; j++)
        {
            //cout << j << endl;
            //cout << "A: " << i << " B: " << j << " A&B: " << (i&j) << endl;
            
            // check if bitwise & fits constraints
            if((i&j) > max && (i&j) < K)
            {
                max = (i&j);
            }
        }
    }
    
    //cout << "----------------------" << endl;
    
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int count = stoi(first_multiple_input[0]);

        int lim = stoi(first_multiple_input[1]);

        int res = bitwiseAnd(count, lim);

        fout << res << "\n";
    }

    fout.close();

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
