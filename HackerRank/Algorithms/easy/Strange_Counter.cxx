#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    long long i = 0;
    long long count = 0;
    while (count < t)
    {
        count += 3 * std::pow(2, i);
        ++i;
    }
    //std::cerr << "count = " << count << "\n";
    return 1 + count - t;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
