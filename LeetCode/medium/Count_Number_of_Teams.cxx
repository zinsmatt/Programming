class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        vector<int> lower_left(rating.size());
        vector<int> lower_right(rating.size());
        vector<int> greater_left(rating.size());
        vector<int> greater_right(rating.size());
        
        for (int i = 0; i < rating.size(); ++i) {
            int count_lower = 0, count_greater = 0;
            for (int j = 0; j < i; ++j) {
                count_lower += rating[j] < rating[i];
                count_greater += rating[j] > rating[i];
            }
            lower_left[i] = count_lower;
            greater_left[i] = count_greater;
        }
        
        
                
        for (int i = rating.size()-1; i >= 0; --i) {
            int count_lower = 0, count_greater = 0;
            for (int j = rating.size()-1; j > i; --j) {
                count_lower += rating[j] < rating[i];
                count_greater += rating[j] > rating[i];
            }
            lower_right[i] = count_lower;
            greater_right[i] = count_greater;
        }
        
        
        int res = 0;
        for (int i = 0; i < rating.size(); ++i) {
            res += lower_left[i] * greater_right[i] + lower_right[i] * greater_left[i];
        }
        return res;
        
    }
};
