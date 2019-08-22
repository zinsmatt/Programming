#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int check(const string& s, char a, char b)
{
    //cout << a << " " << b ;
    
    char prev;
    int n=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == a)
        {
            if(s[i] == prev)
            {
                n=0;break;
            }
            else
                prev = s[i];
            n++;
        }else if(s[i] == b)
        {
            if(prev == b)
            {
                n=0;break;
            }
            else
                prev = s[i];
            n++;
        }
    }
    return n;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    string s;
    cin >> s;
    char c='a';
    int maxi=-99999999;
    for(char a='a';a<='z';a++)
    {
        for(char b=a+1;b<='z';b++)
        {
            if(count(s.begin(),s.end(),a)>0 && count(s.begin(), s.end(),b)>0)
            {
                int nb = check(s,a,b);
                if(nb>maxi)
                    maxi=nb;
            }
        }
    }
    if(maxi<0)
        cout << 0;
    else
    cout << maxi;
    return 0;
}
