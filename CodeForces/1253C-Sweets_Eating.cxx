#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    unsigned long long int n, m;
    cin >> n >> m;
    vector<unsigned long long int> a(n, 0);
    vector<unsigned long long int> r(m, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    unsigned long long int cost = 0;
    for (int k = 1; k <= n; ++k)
    {
        cost += a[k-1] + r[(k-1) % m];
        r[(k-1) % m] += a[k-1];
        cout << cost << " ";
    }
    
    return 0;
}