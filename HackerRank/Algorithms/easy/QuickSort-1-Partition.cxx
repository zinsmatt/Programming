#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> tab(n);
    for(int i=0;i<n;i++) cin>>tab[i];
    int p = tab[0];
    
    int l = 1, r = n-1;
    while(l<r)
    {
        while(l<n && tab[l]<p) l++;
        while(r>0 && tab[r]>p) r--;
        cerr << l << " " << r << endl;
        if(r>l)
        {
            int tmp = tab[l];
            tab[l] = tab[r];
            tab[r] = tmp;
        }
    }
    tab[0] = tab[r];
    tab[r] = p;
    
    
    for(auto c : tab) cout << c << " ";
    
    
    return 0;
}
