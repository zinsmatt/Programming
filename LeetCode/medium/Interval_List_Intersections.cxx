class Solution {
public:
    bool isBefore(vector<int> const& ref, vector<int> const& test)
    {
        return test[1] < ref[0];
    }
    bool isAfter(vector<int> const& ref, vector<int> const& test)
    {
        return test[0] > ref[1];
    }
    vector<int> intersection(vector<int> const& ref, vector<int> const& test)
    {
        return {max(ref[0], test[0]), min(ref[1], test[1])};
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if (A.size() == 0 || B.size() == 0)
            return res;
        int j = 0;
        for (int i = 0; i < B.size(); ++i)
        {
            while (j < A.size() && isBefore(B[i], A[j]))
                ++j;
            if (j >= A.size())
                break;
            
            while (j < A.size() && !isAfter(B[i], A[j]))
            {
                res.emplace_back(intersection(B[i], A[j]));
                ++j;                    
            }
            if (j > 0)
                --j;
        }
        

        
//         vector<vector<int>> merged;
//         int max = -1;
//         for (int i = 0; i < res.size(); ++i)
//         {
//             if (max == res[i][0])
//             {
//                 merged.back()[1] = res[i][1];
//             }
//             else
//             {
//                 merged.emplace_back(res[i]);
//             }
//             max = res[i][1];
//         }
        
        return res;
    }
};