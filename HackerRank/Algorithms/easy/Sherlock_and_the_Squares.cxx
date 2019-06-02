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
    while(n){
        int a,b,nb=0;
        cin >> a >> b;
        cout << floor(sqrt(b)) - ceil(sqrt(a)) + 1 << endl;
        n--;
    }
    return 0;
}
