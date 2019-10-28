class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> indices(ratings.size());
        std::iota(indices.begin(), indices.end(), 0);
        
        std::sort(indices.begin(), indices.end(), [&ratings](int a, int b) {
            return ratings[a] < ratings[b];
        });
        
        vector<int> a(ratings.size(), 0);
        
        int res = ratings.size();
        for (auto idx : indices)
        {
            bool left = true, right = true;
            if (idx == 0 || ratings[idx-1] >= ratings[idx])
                left = false;
            if (idx == ratings.size()-1 || ratings[idx] <= ratings[idx+1])
                right = false;
            int to_add = 0;
            if (left)
                to_add = std::max(to_add, a[idx-1]-a[idx]+1);
            if (right)
                to_add = std::max(to_add, a[idx+1]-a[idx]+1);
            //std::cout << "add " << idx << " " << to_add << std::endl;
            res += to_add;
            a[idx] += to_add;
        }

        return res;
    }
};