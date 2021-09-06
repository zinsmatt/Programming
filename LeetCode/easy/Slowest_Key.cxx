class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int cur = 0;
        int n = releaseTimes.size();
        int max_duration = 0;
        char key;
        for (int i = 0; i < n; ++i)
        {
            auto d = releaseTimes[i]-cur;
            if (d > max_duration)
            {
                max_duration = d;
                key = keysPressed[i];
            } else if (d == max_duration)
            {
                key = std::max(key, keysPressed[i]);
            }
            cur = releaseTimes[i];
        }
        return key;
    }
};
