#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;


int main()
{

   int n, m;
   cin >> n >> m;
   vector<int> likes(m);
   F(i, m)
   {
       cin >> likes[i];
   }
   
   vector<int> maxi(n+1);
   vector<int> mini(n+1);
   std::iota(maxi.begin(), maxi.end(), 0);
   std::iota(mini.begin(), mini.end(), 0);
   vector<int> cur(n+1);
   std::iota(cur.begin(), cur.end(), 0);
   vector<int> feed(n+1);
   std::iota(feed.begin(), feed.end(), 0);

   
   for (auto& l : likes)
   {
        int pos = cur[l];
       if (pos > 1)
       {
           int other = feed[pos-1];
           int new_pos_other = pos;
           maxi[other] = max(maxi[other], new_pos_other);
           
           int new_pos = pos-1;
           mini[l] = min(mini[l], new_pos);
           
           swap(cur[l], cur[other]);
           swap(feed[pos], feed[pos-1]);
       }
   }

   
   for (int i = 1; i <= n; ++i)
   {
       cout << mini[i] << " " << maxi[i] << "\n";
   }
   
   
    return 0;
}