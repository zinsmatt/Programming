class Solution {
    vector<vector<int>> permutations;
    unordered_map<string, int> done;
    
    std::string to_string(const vector<int>& v)
    {
        stringstream ss;
        for (auto x : v)
        {
            ss << x;
        }
        return ss.str();
    }
public:
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do
        {
            auto s = to_string(nums);
            // std::cout << s << "\n";
            if (done.find(s) == done.end())
            {
                done[s] = 1;
                permutations.push_back(nums);
            }
        } while (next_permutation(nums.begin(), nums.end()));
        return permutations;   
    }
};
