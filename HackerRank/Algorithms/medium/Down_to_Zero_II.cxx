#include <bits/stdc++.h>

using namespace std;



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    const int N = 1000001;
    vector<int> arr(N, std::numeric_limits<int>::max());
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 2; i < N; ++i)
    {
        arr[i] = std::min(arr[i-1]+1, arr[i]);
        for (int j = 2; j <= i && i * j < N; ++ j)
        {
            arr[i*j] = std::min(arr[i*j], arr[i] + 1);
        }
    }


    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = arr[n];

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

