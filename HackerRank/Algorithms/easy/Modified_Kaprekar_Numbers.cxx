#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    bool one = false;
    if (p <= 1)
    {
        one = true;
        std::cout << "1 ";
    }

    for (long n = std::max(4, p); n <= q; ++n)
    {
        long d = n * n;
        //std::cerr << "d=  " << d << std::endl;
        std::string s = std::to_string(d);
        int b;
        b = s.size() / 2;
        //std::cerr << "b = " << b << std::endl;
        //std::cerr << s.substr(0, b) << std::endl;
        //std::cerr << s.substr(b, s.size()/2) << std::endl;
        int left = std::stoi(s.substr(0, b));
        int right = std::stoi(s.substr(b, s.size() - b + 1));
        if (left + right == n)
        {
            std::cout << n << " ";
            one = true;
        }
    }
    if (one == false)
    {
        std::cout << "INVALID RANGE";
    }
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
