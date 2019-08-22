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
    for(int i=0;i<n;i++)
        cin >> tab[i];
    
    int copy = tab.back();
    int iter = n-2;
    while(tab[iter]>copy && iter>=0)
    {
        tab[iter+1] = tab[iter--];
        for(auto c : tab) cout << c << " ";
        cout <<endl;
    }
    tab[iter+1] = copy;
    for(auto c : tab) cout << c << " ";
    cout <<endl;
    return 0;
}
