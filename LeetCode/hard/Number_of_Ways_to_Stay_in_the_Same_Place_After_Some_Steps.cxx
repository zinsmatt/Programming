class Solution {
public:
    int numWays(int steps, int arrLen) {
        const long long P = 1000000007ll;
        vector<long long> A(505, 0);
        A[0] = 1;
        for (int i = 0; i < steps; ++i)
        {
            vector<long long> B(505, 0);
            for (int k = 0; k < std::min(arrLen, 505); ++k)
            {
                B[k] = A[k];
                if (k < A.size()-1)
                    B[k] = (B[k] + A[k+1]) % P;
                if (k > 0)
                    B[k] = (B[k] + A[k-1]) % P;
            }
            A = B;
        }
        return A[0] % P;
    }
};
