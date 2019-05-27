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
    int n;
    
    for(int i=0;i<nb;i++)
        {
        int s = 0;
        int x = 0;
        cin>>n;
        int save = n;
        while(n>0)
            {
            int x = n%10;
            if(x!=0 && save%x==0){
                s++;
            }
            n /= 10;
        }
        cout<<s<<endl;
    }
    
    
    return 0;
}
