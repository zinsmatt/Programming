class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int a = 0, b = 1;
        int end = A.size() - 1;
        while (a < A.size() && b < A.size())
        {
            if (A[end] % 2 == 0)
            {
                swap(A[a], A[end]);
                a += 2;
            }
            else
            {
                swap(A[b], A[end]);
                b += 2;
            }
        }
        return A;
    }
};