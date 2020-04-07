class Solution {
public:
    int countElements(vector<int>& arr) {
        vector<int> occ(1001, 0);
        for (auto x : arr)
            occ[x]++;
        long long res = 0;
        for (int i = 1; i < occ.size(); ++i)
        {
            if (occ[i] > 0)
                res += occ[i-1];
        }
        return res;
    }
};
