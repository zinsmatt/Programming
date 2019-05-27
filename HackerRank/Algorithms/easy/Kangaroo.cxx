#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int x1,v1,x2,v2;
    cin >> x1 >> v1 >> x2 >> v2;
    
    float res = static_cast<float>(x1-x2)/(v2-v1);
    if(res>=0 && floor(res) == res) cout << "YES";
    else cout << "NO";
    
    return 0;
}
