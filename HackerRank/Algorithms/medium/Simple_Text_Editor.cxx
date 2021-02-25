#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<string> st;
    string s;
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ++ti)
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            st.push(s);
            string arg;
            cin >> arg;
            s += arg;
            
        } else if (op == 2) 
        {
            st.push(s);
            int arg;
            cin >> arg;
            s = s.substr(0, s.size()-arg);
        } else if (op == 3)
        {
            int arg;
            cin >> arg;
            cout << s[arg-1] << "\n";
        } else
        {
            s = st.top();
            st.pop();
        }
    }
    return 0;
}
