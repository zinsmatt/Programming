class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
        {
            return s;
        }
        std::vector<std::stringstream> zig(numRows);
        std::stringstream ss;
        int row = 0;
        int inc = 1;
        for (auto& c : s)
        {
            zig[row] << c;
            if (row == numRows - 1)
            {
                inc = -1;
            }
            if (row == 0)
            {
                inc = 1;
            }
            row += inc;                   
        }
        
        for (auto const& z : zig)
        {
            ss << z.str();            
        }
        return ss.str();
    }
};