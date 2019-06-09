#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n_topics;

int calc_topics(string a,string b)
{
    int s=0;
    for(int i=0;i<n_topics;i++)
        {
        if(a[i]=='1' || b[i]=='1')
            s++;
    }
    return s;   
}



int main() {
    vector<string> tab;
    int n_persons;
    cin>>n_persons;
    cin>>n_topics;
    string str;
    for(int i=0;i<n_persons;i++){
        cin>>str;
        tab.push_back(str);
    }
    int max = 0;
    int nmax = 0;
    for(int i=0;i<n_persons;i++)
    {
        
        for(int j=i+1;j<n_persons;j++)
        {   
            int connus = calc_topics(tab[i],tab[j]);
            if(connus == max){
                nmax++;
            }
            else if(connus>max)
            {
                max = connus;
                nmax = 1;
            }
        }
    }
    cout<<max<<endl<<nmax<<endl;
    
    return 0;
}
