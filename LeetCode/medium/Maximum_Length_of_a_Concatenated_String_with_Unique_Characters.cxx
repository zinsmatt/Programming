class Solution {
    int solve(vector<string>& arr, vector<int>& alpha, int count, int i)
    {
        if (i >= arr.size())
            return count;
        
        int ret = solve(arr, alpha, count, i+1);
        auto temp = alpha;
        bool ok = true;
        for (auto c : arr[i])
        {
            if (alpha[c-'a'])
                ok = false;
            if (temp[c-'a'] == 1)
                ok = false;
            temp[c-'a'] = 1;
        }
        if (ok)
        {
            ret = std::max(ret, solve(arr, temp, count+arr[i].size(), i+1));
        }
        
        return ret;
    }
    
    
public:
    
    int maxLength(vector<string>& arr) {
        vector<int> alpha(26, 0);
        return solve(arr, alpha, 0, 0);
    }
};
