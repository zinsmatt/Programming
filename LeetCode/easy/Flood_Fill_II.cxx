class Solution {
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        std::queue<pair<int, int>> q;
        q.push({sr, sc});
        int g = image[sr][sc];
        if (g == color)
            return image; // this way no need to keep track of the filled pixels
        // std::unordered_set<int> done;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (image[r][c] != g)
                continue;
            // int h = r * 100 + c;
            //if (done.count(h))
            //    continue;
            
            if (r > 0)
                q.push({r-1, c});
            if (r < image.size()-1)
                q.push({r+1, c});

            if (c > 0)
                q.push({r, c-1});
            if (c < image[0].size()-1)
                q.push({r, c+1});

            image[r][c] = color;
            // done.insert(h);            
        }
        return image;
    }
};
