class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int cur = 0;
        for (auto n : A)
            if (n % 2 == 0)
                cur += n;
        for (auto const& q : queries)
        {
     
            int val = q[0];
            int idx = q[1];
            if (abs(A[idx]) % 2 == 0)
            {
                if (abs(val) % 2 == 0)
                {
                    cur += val;
                }
                else
                {
                    cur -= A[idx];
                }
            }
            else
            {
                if (abs(val) % 2 == 1)
                {
                    cur += A[idx] + val;
                }
            }
            A[idx] += val;
            
            res.push_back(cur);
        }
        return res;
    }
};