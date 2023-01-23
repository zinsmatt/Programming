class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n, 0);
        vector<int> trustee(n, 0);

        for (auto &v : trust) {
            int a = v[0];
            int b = v[1];
            ++trusted[b-1];
            ++trustee[a-1];
        }

        for (int i = 0; i < n; ++i) {
            if (trusted[i] == n-1 && trustee[i] == 0)
                return i+1;
        }
        return -1;

    }
};
