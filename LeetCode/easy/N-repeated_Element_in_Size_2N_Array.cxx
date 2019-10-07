class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        vector<int> count(10001, 0);
        for (auto& x : A)
        {
            if (count[x] == 0)
                ++count[x];
            else
                return x;
        }
        return 0;
    }
};