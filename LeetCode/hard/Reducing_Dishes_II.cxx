class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int i = 0;
        while (i < n && satisfaction[i] < 0)
            ++i;
        
        if (i >= n)
            return 0;

        int j = i-1;
        long s = 0;
        long add = 0;
        int k = 1;
        while (i < n) {
            s += k * satisfaction[i];
            add += satisfaction[i];
            ++k;
            ++i;
        }

        while (j >= 0) {
            if (abs(satisfaction[j]) <= add) {
                add += satisfaction[j];
                s += add;
            }
            --j;
        }
        return s;

    }
};
