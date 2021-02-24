#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

std::stack<int> s1, s2;

void enqueue(int x)
{
    s1.push(x);
}

void print()
{
    if (s2.size() == 0)
    {
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    std::cout << s2.top() << "\n";
}

int dequeue()
{
    if (s2.size() == 0)
    {
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    auto res = s2.top();
    s2.pop();
    return res;        
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ++ti)
    {
        int op;
        cin >> op;
        int arg;
        if (op == 1) {
            cin >> arg;
            enqueue(arg);
        } else if (op == 2) {
            dequeue();
        }
        else {
            print();
        }
    }
    return 0;
}

