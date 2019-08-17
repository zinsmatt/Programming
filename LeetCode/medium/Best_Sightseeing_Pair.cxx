class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int max = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = i+1; j < A.size(); ++j)
            {
                int s = A[i] + A[j] + i - j;
                if (s > max)
                    max = s;
                if (j - i > A[i])
                    break;
            }
        }
        return max;
    }
};