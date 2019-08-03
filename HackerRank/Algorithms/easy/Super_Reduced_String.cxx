#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string reduce(const string& s)
{
    string nouv;
    for(int i=0;i<s.size();i++)
    {
        if(i==s.size()-1 || s[i]!=s[i+1])
        {
            nouv+=s[i];
        }else
            i++;
    }
    return nouv;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s,s2;
    cin >> s2;
    
    do
    {
        s = s2;
        s2 = reduce(s);
        //cout << s2 << endl;
    }while(s2.empty() == false && s!=s2);
    
    if(s2.empty())
        cout << "Empty String";
    else
        cout << s2;
    
    return 0;
}
