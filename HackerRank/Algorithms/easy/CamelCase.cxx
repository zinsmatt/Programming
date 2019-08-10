#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin >> s;
    int nb = 1, i=0;
    while(i<s.size())
    {
        if(s[i]<='Z' && s[i]>='A')
            nb++;
        i++;
    }
    cout << nb ;
    return 0;
}
