class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        auto initCol = image[sr][sc];
        if (initCol == newColor)
            return image;
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            if (image[r][c] == initCol)
            {
                image[r][c] = newColor;
                if (r > 0)
                    q.push({r-1, c});
                if (c > 0)
                    q.push({r, c-1});
                if (r < image.size()-1)
                    q.push({r+1, c});
                if (c < image[0].size()-1)
                    q.push({r, c+1});
            }
        }
        return image;
    }
};
