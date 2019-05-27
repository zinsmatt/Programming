#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    vector<long> tab(5);
    for(int i=0;i<5;i++)
    {
        cin >> tab[i];
    }
    
    sort(tab.begin(),tab.end());
    
    cout << tab[0]+tab[1]+tab[2]+tab[3] << " ";
    cout << tab[3]+tab[1]+tab[2]+tab[4] << endl;

    return 0;
}
