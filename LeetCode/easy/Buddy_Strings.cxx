class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size())
            return false;
        int swapIdx = -1;
        int done = false;
        vector<int> count(26, 0);
        for (int i = 0; i < A.size(); ++i)
        {
            count[B[i]-'a']++;
            if (A[i] != B[i])
            {
                if (done)
                    return false;
                if (swapIdx == -1)
                {
                    swapIdx = i;
                }
                else
                {
                    if (A[i] == B[swapIdx] && A[swapIdx] == B[i])
                    {
                        done = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if (done)
            return true;
        else
            return *max_element(count.begin(), count.end()) > 1;
        return true;   
    }
};