#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    if (n == 1) return 2;

    int acc = 2;
    int liked = 2;
    for (int i = 2; i <= n; ++i)
    {
        int nb = liked * 3;
        liked = std::floor(nb / 2);
        acc += liked;
    }
    return acc;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
