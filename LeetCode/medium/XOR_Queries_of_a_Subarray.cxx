class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xor_cum(arr.size());
        xor_cum[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i)
        {
            xor_cum[i] = xor_cum[i-1] ^ arr[i];
        }
        
        vector<int> res(queries.size());
        int a = 0;
        for (auto q : queries)
        {
            if (q[0] == 0)
            {
                res[a++] = xor_cum[q[1]];
            }
            else
            {
                res[a++] = xor_cum[q[0]-1] ^ xor_cum[q[1]];
            }
        }
        return res;
    }
};
