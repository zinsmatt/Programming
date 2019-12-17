#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    char ref = s[0];
    vector<int> op;
    for (int i = 1; i < n-1; ++i)
    {
        if (s[i] != ref)
        {
            op.push_back(i+1);
            s[i] = ref;
            if (s[i+1] == 'B')
                s[i+1] = 'W';
            else
                s[i+1] = 'B';
        }
    }
    if (s.back() == ref)
    {
        cout << op.size() << "\n";
        if (op.size() > 0)
        {
            for (auto o : op)
                cout << o << " ";
            cout << "\n";
        }
    }
    else if ((n-1) % 2 == 0)
    {
        for (int i = 0; i < n-1; i += 2)
            op.push_back(i+1);
        cout << op.size() << "\n";
        if (op.size() > 0)
        {
            for (auto o : op)
                cout << o << " ";
            cout << "\n";
        }
    }
    else
    {
        cout << -1 << "\n";
    }
    
    
    return 0;
}