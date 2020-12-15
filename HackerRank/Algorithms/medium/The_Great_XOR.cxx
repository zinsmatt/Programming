#include <bits/stdc++.h>

using namespace std;

// Complete the theGreatXor function below.
long theGreatXor(long x) {
    long res = 0;
    int index = 0;
    while (x)
    {
        if (x % 2 == 0) {
            res += std::pow(2, index); 
        }
        ++index;
        x /= 2;
    }
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = theGreatXor(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

