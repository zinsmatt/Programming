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
    stack<int> st;
    int c = 0;
    F(i, n)
    {
        if (s[i] == '(')
            ++c;
        else
            --c;
        if (st.size() > 0)
        {
            if (s[i] == ')' && st.top() == '(')
            {
                st.pop();
                continue;
            }
        }
        st.push(s[i]);
    }
    if (st.size() == 0 || c == 0 && st.size() == 2)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}
