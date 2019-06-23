#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your cod. Read input from STDIN. Print output to STDOUT */   
    int a, b;
    cin >> b >> a;
    double r = 2.0 * static_cast<double>(a) / b;
    std::cout << static_cast<int>(std::ceil(r));

    return 0;
}
