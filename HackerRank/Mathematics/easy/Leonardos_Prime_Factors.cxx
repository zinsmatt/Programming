#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the primeCount function below.
 */
int pr[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int primeCount(unsigned long long int n) {
    /*
     * Write your code here.
     */
    if (n == 1) return 0;
    unsigned long long int res = 1;
    int c = 0;
    for (int i = 0; i < 16; ++i)
    {
        res *= pr[i];
        if (res <= n)
            ++c;
        else
            break;

    }
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = primeCount(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
