class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> occ;
        vector<int> others;
        for (auto k : arr2)
        {
            occ[k] = 0;
        }
        for (auto k : arr1)
        {
            if (occ.find(k) == occ.end())
                others.push_back(k);
            else
                occ[k]++;
        }
        
        sort(others.begin(), others.end());
        vector<int> res;
        for (auto k : arr2)
        {
            for (int i = 0; i < occ[k]; ++i)
                res.push_back(k);
        }
        res.insert(res.end(), others.begin(), others.end());
        return res;
    }
};