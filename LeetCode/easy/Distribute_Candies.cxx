class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int, int> m;
        int n = 0;
        for (auto c : candies)
        {
            if (m.find(c) == m.end())
            {
                n++;
            }
            m[c] = 1;
        }
        return std::min(n, (int)candies.size() / 2);
        
    }
};