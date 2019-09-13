class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> road(1001, 0);
        for (int i = 0; i < trips.size(); ++i)
        {
            const auto& t = trips[i];
            std::transform(road.begin()+t[1], road.begin()+t[2], road.begin()+t[1], [&t] (int x) {
                return x + t[0];
            });
        }
        for (auto k : road)
        {
            if (k > capacity)
                return false;
        }
        return true;
    }
};