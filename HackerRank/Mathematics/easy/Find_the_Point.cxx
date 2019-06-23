#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int nb;
    cin>>nb;
    for(int i=0;i<nb;i++)
    {
        int px,py,qx,qy;
        cin >> px >> py >>qx >> qy;
                
        
        int vx = qx,vy = qy;
        
        px -= vx;
        py -= vy;
        
        px *= -1;
        py *= -1;
        
        px += vx;
        py += vy;
        
        cout<<px<<" "<<py<<endl;
        
        
        
    }
    return 0;
}
