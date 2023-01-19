class Solution {
    std::deque<int> dq;
public:
    void print() {
        for (auto x : dq)
        cout << x << " ";
        cout << " \n";
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out(nums.size()-k+1, 0);

        for (int i = 0; i < k-1; ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        // print();
        int r = k-1;

        for (int i = 0; i < out.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[r])
                dq.pop_back();
            dq.push_back(r);
            // print();
            
            out[i] = nums[dq.front()];

            if (dq.front() == i)
                dq.pop_front();
            ++r;
        }
        return out;
    }
};
