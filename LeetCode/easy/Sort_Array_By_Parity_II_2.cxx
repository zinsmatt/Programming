class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res(A.size(), 0);
        int even = 0, odd = A.size()-1;
        for (auto v : A)
        {
            if (v % 2 == 0)
            {
                res[even++] = v;
            }
            else
            {
                res[odd--] = v;
            }
        }
        return res;
    }
};