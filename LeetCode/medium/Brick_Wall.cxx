class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        std::unordered_map<int, int> map;
        for (auto &row : wall)
        {
            int x = 0;
            for (int i = 0; i < row.size() - 1; ++i)
            {
                x += row[i];
                if (map.find(x) != map.end())
                {
                    map[x]++;
                }
                else
                    map[x] = 1;
            }
        }
        int max = 0;
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (it->second > max)
                max = it->second;
        }
        return wall.size() - max;
    }
};