#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    std::array<int, 26> count;
    std::fill(count.begin(), count.end(), 0);
    for (auto const& s : arr)
    {
      std::array<int, 26> occ;
      std::fill(occ.begin(), occ.end(), 0);
      for (char c : s)
      {
          occ[c - 'a'] = std::min(occ[c - 'a'] + 1, 1);
      }
      for (int i =0; i < 26; ++i)
      {
          count[i] += occ[i];
      }
    }

    for (auto c : count)
        std::cerr << c <<  " " ;
    std::cerr << "\n";
    int n = 0;
    for (auto c : count)
        if (c >= arr.size())
            n++;
    return n;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
