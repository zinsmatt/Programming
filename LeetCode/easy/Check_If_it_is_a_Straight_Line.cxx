class Solution {
    
    int cross(const vector<int>& a, const vector<int>& b)
    {
        return a[0] * b[1] - a[1] * b[0];
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n = coordinates.size();
        if (n == 2)
            return true;
        std::vector<int> v01 = {coordinates[1][0]-coordinates[0][0], coordinates[1][1]-coordinates[0][1]};
        for (int i = 1; i < n; ++i)
        {
            if (cross(v01, {coordinates[i][0]-coordinates[0][0], coordinates[i][1]-coordinates[0][1]}) != 0)
                return false;
        }
        return true;
    }
};
