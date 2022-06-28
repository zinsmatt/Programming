class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for (auto x : nums) {
            if (s.count(x))
                return true;
            else
                s.insert(x);
        }
        return false; 
    }
};
