#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,c,m;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        int answer=0;
        int argent = n;
        int choco = 0;
        int wrap = 0;
        int chocos = n / c;
        answer += chocos;
        do
        {
           wrap = chocos / m;
           chocos = chocos % m;
           answer += wrap;
           chocos += wrap;
                    
        }while(wrap>0);
        
        
        
        cout<<answer<<endl;
    }
    return 0;
}



    