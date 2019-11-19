class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        map<int, bool> occ;
        for (auto& a: A)
            occ[a] = true;
        sort(A.begin(), A.end());
        int res = 0;
        int min_idx = 0;
        int prev = -1;
        for (auto& a : A)
        {
            if (prev != a)
            {
                prev = a;
                continue;
            }
            else
            {
                while (min_idx <= prev || occ.find(min_idx) != occ.end())
                {
                    min_idx++;
                }
                occ[min_idx] = true;
                res += min_idx - a;
                prev = a;
            }
        }
        return res;    
    }
};