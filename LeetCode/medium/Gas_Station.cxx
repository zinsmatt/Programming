class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            auto d = gas[i] - cost[i];
            sum += d;
        }
        if (sum < 0) 
            return -1;
        
        int cur_sum = 0;
        int cur_sum_max = std::numeric_limits<int>::min();
        int max_i = -1;
        for (int i = gas.size()-1; i >= 0; --i)
        {
            cur_sum += gas[i] - cost[i];
            if (cur_sum > cur_sum_max)
            {
                cur_sum_max = cur_sum;
                max_i = i;
            }
        }
        return max_i;
    }
};
        

