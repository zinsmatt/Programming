class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        if (A.size() <= 1)
            return res;
        for (int i = A.size(); i > 1; --i)
        {
            int max_index = distance(A.begin(), max_element(A.begin(), A.begin() + i));
            res.push_back(max_index+1);
            reverse(A.begin(), A.begin() + max_index+1);
            
            res.push_back(i);
            reverse(A.begin(), A.begin() + i);
        }
        return res;
        
    }
};