#include <iostream>
#include <bits/stdc++.h>

using namespace std;




int main()
{
    int t;
    cin >> t;
    
    
    for (int i = 0; i < t; ++i)
    {
        int d;
        cin >> d;
        double delta = d*d - 4*d;
        if (delta < 0)
        {
            std::cout << "N\n";
        }
        else
        {
            double sqDelta = sqrt(delta);
            double s1 = (-d-sqDelta) / (-2);
            
            printf("Y %.9lf %.9lf\n", s1 , d - s1);
        }
    }
    return 0;
}