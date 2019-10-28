/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& fct, int z) {
        vector<vector<int>> res;
        for (int x = 1; x <= 1000; ++x)
        {
            if (fct.f(x, 0) > z)
                break;
            for (int y = 1; y <= 1000; ++y)
            {
                if (fct.f(x, y) > z)
                    break;
                else if (fct.f(x, y) == z)
                    res.push_back(vector<int>({x, y}));
            }
        }
        return res;        
    }
};