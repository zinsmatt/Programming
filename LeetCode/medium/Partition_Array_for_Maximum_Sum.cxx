class Solution {
public:
    int max(vector<int> const& A, int l, int r)
    {
        return *max_element(A.begin() + l, A.begin() + r + 1);
    }
    
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size(), 0);
        // init the K first elements
        for (int i = 0; i < K; ++i)
        {
            dp[i] = (i+1) * max(A, 0, i);
        }
        
        for (int i = K; i < A.size(); ++i)
        {
            vector<int> tmp(K, 0);              // here keeping the elements and then find th emax is not necessary
                                                // on could only keep the max
            for (int j = 0; j < K; ++j)
            {
                tmp[j] = dp[i-1-j] + max(A, i-j, i) * (j+1);
            }
            dp[i] = *max_element(tmp.begin(), tmp.end());         
        }
        return dp.back();
    }
};