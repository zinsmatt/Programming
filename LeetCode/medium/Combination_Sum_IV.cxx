class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::queue<pair<vector<int>, pair<int, int>>> q;
        for (int i = 0; i < candidates.size(); ++i) {
            auto& x = candidates[i];
            q.push({{x}, {x, i-1}});
        }
        vector<vector<int>> res;
        
        while (!q.empty()) {
            
            auto [v, p] = q.front();
            auto [s, k] = p;
            q.pop();
            if (s == target)
                res.emplace_back(std::move(v));
            else
            {
                for (int i = k+1; i < candidates.size(); ++i) {
                    auto& c = candidates[i];
                    int count = 1;
                    auto vv = v;
                    auto ss = s;
                    while (s + c * count <= target){
                        vv.push_back(c);
                        ss += c;
                        q.push({vv, {ss, i}});
                        ++count;
                    }
                }
            }
        }
        return res;
    }
};
