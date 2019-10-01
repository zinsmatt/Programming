class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> occ(2001, 0);
        for (auto const& v : arr)
        {
            occ[1000+v]++;
        }
        vector<int> uni(1001, 0);
        for (auto& o : occ)
        {
            if (o > 0)
            {
                if (uni[o] > 0)
                    return false;
                else
                    uni[o]++;
            }
        }
        return true;
    }
};
