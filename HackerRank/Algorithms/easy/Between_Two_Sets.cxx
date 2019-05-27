#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    
    int mini = *max_element(a.begin(),a.end());
    int maxi = *min_element(b.begin(),b.end());
    int nb=0;

    for(int val=mini;val<=maxi;val++)
    {
        //cout << val << endl;
        bool oka=true, okb = true;
        for(auto v : a)
            if(val%v!=0){
                //cout << "error a -> " << v << " mod " << val << " = " << v%val << endl;
                oka = false;
                break;
            }
        if(oka)
        {
            for(auto v : b)
                if(v%val!=0){
                //cout << "error b -> " << val << " mod " << v << endl;
                    okb = false;
                    break;
                }
        }
        if(oka && okb) nb++;
    }
    cout << nb;
    return 0;
}
