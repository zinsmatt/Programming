class Solution {
public:

    int solve(int i, vector<int>& manager, vector<int>& informTime, vector<int> &times) {
        if (manager[i] == -1)
            return 0;

        if (times[i] != -1)
            return times[i];
        
        times[i] = solve(manager[i], manager, informTime, times) + informTime[manager[i]];
        return times[i];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> times(n, -1);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, solve(i, manager, informTime, times));
        }
        return res;
    }
};
