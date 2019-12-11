#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;


int main()
{

   int n, m;
   cin >> n;
   
   int mini = std::numeric_limits<int>::max();
   for (int h = 1; h <= sqrt(n); ++h)
   {
       if (n % h == 0)
       {
           mini = min(mini, 2*h+2*(n/h));
       }
   }
   cout << mini;
 
   
    return 0;
}