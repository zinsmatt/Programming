#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    string s;
    char x;
    cin>>n;
    char map[n][n];
    char map2[n][n];
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            map[i][j] = s[j];
            map2[i][j] = map[i][j];
        }}
    

    for(int i=1;i<n-1;i++)
        for(int j=1;j<n-1;j++)
        {
            x = map[i][j];
            if(map[i-1][j]<x && map[i+1][j]<x && map[i][j-1]<x && map[i][j+1]<x )
            {
                map2[i][j] = 'X';
            }
        }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map2[i][j];
        }
         cout<<endl;
     }
    
    return 0;
}
