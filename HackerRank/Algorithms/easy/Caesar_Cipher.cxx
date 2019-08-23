#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,offset;
    string s;
    cin >> n;
    cin >> s;
    cin >> offset;
    for(int i=0;i<s.size();i++)
    {
        char c = s[i];
        if(c>='a' && c<='z')
            cout << static_cast<char>('a' + ((c-'a')+offset)%26);
        else if(c>='A' && c<='Z')
            cout << static_cast<char>('A' + ((c-'A')+offset)%26);
        else cout << c;
    }
    return 0;
}
