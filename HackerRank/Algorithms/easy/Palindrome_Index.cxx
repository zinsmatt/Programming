#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 bool isPal(const string& s, int l, int r)
 {
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        ++l;
        --r;        
    }
    return true;
 }

int palindromeIndex(string s) {
    int l = 0;
    int r = s.size()-1;
    while (l < r)
    {
        if (s[l] != s[r]){
            break;
        }
        else {
            ++l;
            --r;
        }
    }
    
    if (l >= r) return -1;
    
    if (isPal(s, l+1, r)) {
        return l;
    } else if (isPal(s, l, r-1)) {
        return r;
    } else {
        return -1;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
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

