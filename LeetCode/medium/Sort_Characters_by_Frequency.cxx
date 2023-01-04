class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(100, 0);
        for (auto c : s) {
            freq[c-'0']++;
        }

        vector<int> ind(100);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&freq](int a, int b) {
            return freq[a] > freq[b];
        });

        stringstream res;
        for (auto i : ind) {
            for (int j = 0; j < freq[i]; ++j) {
                res << static_cast<char>('0'+i);
            }
        }
        return res.str();
    }
};
