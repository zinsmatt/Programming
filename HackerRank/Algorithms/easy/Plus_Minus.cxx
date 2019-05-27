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
    int pos=0,neg=0,zer=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x>0) pos++;
        else if(x<0) neg++;
        else zer++;
    }
    
    double fpos,fneg,fzer;
    fpos = static_cast<double>(pos) / n;
    fneg = static_cast<double>(neg) / n;
    fzer = static_cast<double>(zer) / n;
    cout << fpos << endl << fneg << endl << fzer << endl;
    
    return 0;
}
