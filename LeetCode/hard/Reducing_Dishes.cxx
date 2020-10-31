class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), std::greater<int>());
        int s = 0;
        int n = satisfaction.size();
        int used = 0;
        for (int i = 0; i < n; ++i)
        {
            if (used + satisfaction[i] >= 0)
            {
                s += satisfaction[i] + used;
                used += satisfaction[i];
            }            
        }
        return s;
        
    }
};
