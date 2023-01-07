class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size());
        int total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            diff[i] = gas[i] - cost[i];
            total += diff[i];
        }
        if (total < 0)
            return -1;

        int cum = 0;
        int cum_max = -1;
        int res = -1;
        for (int i = gas.size()-1; i >= 0; --i) {
            cum += diff[i];
            if (cum > cum_max) {
                cum_max = cum;
                res = i;
            }
        }
        return res;
    }
};
