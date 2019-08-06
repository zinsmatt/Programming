class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int a = A[0];
        res.push_back(a % 5 == 0);
        for (int i = 1; i < A.size(); ++i)
        {
            a = a * 2 + A[i];
            a = a % 5;
            res.push_back(a % 5 == 0);
        }
        return res;
    }
};