class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int> occ;
        for (auto x : arr)
        {
            if (occ.find(x) != occ.end())
            {
                occ[x]++;
            }
            else
            {
                occ[x] = 1;
            }
        }
        
        vector<int> counts;
        for (auto it : occ)
        {
            counts.push_back(it.second);
        }
        
        sort(counts.begin(), counts.end(), std::greater<int>());
        std::partial_sum(counts.begin(), counts.end(), counts.begin(), std::plus<int>());
        auto res = std::distance(counts.begin(), lower_bound(counts.begin(), counts.end(), arr.size() / 2)) + 1;
        return res;        
    }
};
