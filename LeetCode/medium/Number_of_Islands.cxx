class Solution {
    
    void dfs(int index)
    {
        if (!done[index])
        {
            done[index] = true;
            for (auto e : g[index])
            {
                if (!done[e])
                    dfs(e);
            }
        }
    }
    
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> done;

public:
    int numIslands(vector<vector<char>>& grid) {

        int h = grid.size();
        if (h == 0)
            return 0;
        int w = grid.front().size();
        
        vector<int> nodes;
        
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (grid[i][j] == '1')
                {
                    int index = i*w+j;
                    g[index] = vector<int>();
                    if (i > 0 && grid[i-1][j] == '1')
                    {
                        int idx2 = (i-1)*w+j;
                        g[idx2].push_back(index);
                        g[index].push_back(idx2);
                    }
                    
                    if (j > 0 && grid[i][j-1] == '1')
                    {
                        int idx2 = i*w+j-1;
                        g[idx2].push_back(index);
                        g[index].push_back(idx2);
                    }
                    nodes.push_back(index);
                    done[index] = false;
                }
            }
        }

        int res = 0;
        int a = 0;
        while (a < nodes.size())
        {
            while (a < nodes.size() && done[nodes[a]]) ++a;
            
            if (a < nodes.size())
            {
                //cout << "call on " << nodes[a] << "\n";
                dfs(nodes[a]);
                ++res;               
            }
        }
        
        
        return res;
        
    }
};
