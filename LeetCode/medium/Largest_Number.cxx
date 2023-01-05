class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            v[i] = std::to_string(nums[i]);
        }

        sort(v.begin(), v.end(), [](const std::string& a, const std::string& b) {
            return a+b > b+a;
        });

        if (v[0] == "0")
            return "0";
        
        
        stringstream ss;
        for (auto &s : v) {
            ss << s;
        }
        return ss.str();        
    }
};
