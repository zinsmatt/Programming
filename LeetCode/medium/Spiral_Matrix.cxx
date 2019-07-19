class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int a = 0;
        int b = matrix[0].size()-1;
        int c = 0;
        int d = matrix.size()-1;
        
        int x = 0, y = 0;
        while (a <= b && c <= d)
        {
            bool moved = false;
            while (x <= b)
            {
                res.push_back(matrix[y][x++]);
                moved = true;
            }
            if (!moved)
                break;
            x--;
            y++;
            c++;
            moved = false;
            while (y <= d)
            {
                res.push_back(matrix[y++][x]);
                moved = true;
            }
            if (!moved)
                break;
            y--;
            x--;
            b--;
            moved = false;
            while (x >= a)
            {
                res.push_back(matrix[y][x--]);
                moved = true;   
            }
            if (!moved)
                break;
            x++;
            y--;
            d--;
            moved = false;
            while (y >= c)
            {
                res.push_back(matrix[y--][x]);
                moved = true;
            }
            if (!moved)
                break;
            y++;
            x++;
            a++;
        }    
        return res;
    }
};