class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> count(queries.size(), 0);
        int ic = 0;
        for (auto& q : queries) {
            for (auto& p : points) {
                if (std::pow(p[0]-q[0], 2) + std::pow(p[1]-q[1], 2) <= q[2]*q[2])
                    ++count[ic];
            }
            ++ic;
        }
        return count;
    }
};
