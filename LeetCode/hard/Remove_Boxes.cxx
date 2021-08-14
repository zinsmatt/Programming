class Solution {
    int dp[100][100][100];
    
    
    int solve(const vector<int>& boxes, int l, int r, int c)
    {

        if (l > r) return 0;
        if (dp[l][r][c] > 0) return dp[l][r][c];
        int ll = l, rr = r, cc =c;
        
        
        ++c;
        while (l+1 <= r && boxes[l+1] == boxes[l])
        {
            ++l;
            ++c;
        }
        

        int res = c*c + solve(boxes, l+1, r, 0);
        for (int i = l+1; i <= r; ++i)
        {
            if (boxes[i] == boxes[l])
            {
                res = std::max(res, solve(boxes, i, r, c) + solve(boxes, l+1, i-1, 0));
            }
        }
        dp[ll][rr][cc] = res;
        return res;
    }
    
    
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
    
        return solve(boxes, 0, n-1, 0);
      
    }
};
