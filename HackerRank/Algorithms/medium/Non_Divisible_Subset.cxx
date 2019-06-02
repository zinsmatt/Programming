#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int m(const vector<int>& v){
    int min = v[0];
    for(int i=1;i<v.size();i++)
        if(v[i]<min)
            min = v[i];
    return min;
}


int main() {
    int nb,x,min=0,s=0;
    cin>>nb;
        
    vector<int> v;
    for(int i=0;i<nb;i++){
        cin>>x;
        v.push_back(x);
    }
    
    while(v.size()>0)
        {
            s=0;
            min = m(v);
            for(int i=0;i<v.size();i++){
                v[i]-=min;
                s++;
            }
            
            for(int i=v.size()-1;i>=0;i--)    
                if(v[i]==0)
                    v.erase(v.begin()+i);
                
            cout<<s<<endl;
    }
    
    
    
    return 0;
}
