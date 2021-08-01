class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int> values(n*n,0);
        vector<vector<int>> done(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1 && !done[i][j])
                {
                    std::unordered_map<int, int> borders;
                    std::queue<pair<int, int>> q;
                    q.push({i, j});
                    
                    done[i][j] = 1;
                    int count = 0;
                    while (!q.empty())
                    {
                        
                        auto [i, j] = q.front();
                        q.pop();
                        ++count;
                        
                        if (i > 0)
                        {
                            if (grid[i-1][j])
                            {
                                if (!done[i-1][j])
                                {
                                    q.push({i-1,j });
                                    done[i-1][j] = 1;
                                }
                            }
                            else
                            {
                                borders[(i-1)*n+j] = 1;
                            }
                        }
                        
                                                
                        if (j > 0)
                        {
                            if (grid[i][j-1])
                            {
                                if (!done[i][j-1])
                                {
                                    q.push({i,j-1});
                                    done[i][j-1] = 1;
                                }
                            }
                            else
                            {
                                borders[i*n+j-1] = 1;
                            }
                        }
                        
                                                
                        if (i < n-1)
                        {
                            if (grid[i+1][j])
                            {
                                if (!done[i+1][j])
                                {
                                    q.push({i+1,j });
                                    done[i+1][j] = 1;
                                }
                            }
                            else
                            {
                                borders[(i+1)*n+j] = 1;
                            }
                        }
                        
                                            
                        if (j < n-1)
                        {
                            if (grid[i][j+1])
                            {
                                if (!done[i][j+1])
                                {
                                    q.push({i,j+1});
                                    done[i][j+1] = 1;
                                }
                            }
                            else
                            {
                                borders[i*n+j+1] = 1;
                            }
                        }
                    }
                    //std::cout << "count = " << count << "\n";
                    
                    for (auto it : borders)
                    {
                        values[it.first] += count;
                    }
                }
            }
        }
        //for (int i = 0 ; i < values.size(); ++i) cout << values[i] << "\n";
        auto res = *std::max_element(values.begin(), values.end())+1;
        if (res == 1)
        {
            if (done[0][0])
                res = n*n;
        }
        return res;
    }
};
