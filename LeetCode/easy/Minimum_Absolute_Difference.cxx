class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int min = std::numeric_limits<int>::max();
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            int d = arr[i+1] - arr[i];
            if (d < min)
            {
                min = d;
                res.clear();
                res.push_back({arr[i], arr[i+1]});
            }
            else if (d == min)
            {
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};