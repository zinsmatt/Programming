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
    vector<string> tab(n);
    for(int i=0;i<n;i++)
        cin >> tab[i];
    sort(tab.begin(), tab.end(),[](const string& a, const string& b) {
        if(a.size() < b.size()) return true;
        else if(a.size() == b.size()){
            int iter = 0;
            while(iter<a.size() && a[iter]==b[iter]) iter++;
            if(iter==a.size()) return false;
            else if(a[iter] < b[iter]) return true;
            else return false;
        }else
            return false;
    });
    for(auto s : tab)
        cout << s << endl;
    return 0;
}
