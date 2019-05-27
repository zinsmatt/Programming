#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    long long accu=0;
    for(int i=0;i<n;i++)
    {
        long long int tmp;
        cin >> tmp;
        accu += tmp;
    }
    cout << accu;
    return 0;
}
