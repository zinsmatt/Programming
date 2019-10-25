class Solution {
public:
    const float a = 0.78539816339;
    const float cos_a = std::cos(a);
    const float sin_a = std::sin(a);
    const float factor = 4.0 / std::sqrt(2.0);
    
    vector<vector<int>> gridify(const vector<vector<float>>& pts)
    {
        vector<vector<int>> pts_i(pts.size(), vector<int>(2, 0));
        for (int i = 0; i < pts.size(); ++i)
        {
            pts_i[i][0] = (int) round(factor * (cos_a * pts[i][0] - sin_a * pts[i][1]));
            pts_i[i][1] = (int) round(factor * (sin_a * pts[i][0] + cos_a * pts[i][1]));
        }
        return pts_i;
    }
    
    bool is_inside(const vector<vector<int>>& corners, float x, float y)
    {
        vector<vector<float>> v(4, vector<float>(2));
        for (int i = 0; i < 4; ++i)
        {
            v[i][0] = x - corners[i][0];
            v[i][1] = y - corners[i][1];
            // std::cout << corners[i][0] << " " << corners[i][1] << std::endl;
        }
        // std::cout << x << " " << y  << std::endl;
        double sum = 0.0;
        for (int i = 0; i < 4; ++i)
        {
            sum += abs(v[i][0]*v[(i+1)%4][1] - v[i][1]*v[(i+1)%4][0]);
        }
        
        double factor = -2.0 * ((corners[1][0]-corners[0][0]) * (corners[3][1]-corners[0][1]) - 
                               (corners[1][1]-corners[0][1]) * (corners[3][0]-corners[0][0]));
        // std::cout << "ratio = " << sum / factor << std::endl;
        if (sum / factor > 1.001)
            return false;
        else 
            return true;
    }
    
    bool spread(vector<vector<int>>& m, const vector<vector<int>>& corners, int x, int y, int v)
    {
        if (x < 0 || x >= m.size() || y < 0 || y >= m.size())
            return false;
        if (m[y][x] != 0)
            return false;
        if (!is_inside(corners, x, y))
        {
            m[y][x] = -1;
            return false;
        }
        else
        {
            m[y][x] = v;
            spread(m, corners, x-1, y, v);
            spread(m, corners, x, y-1, v);
            spread(m, corners, x+1, y, v);
            spread(m, corners, x, y+1, v);
            return true;
        }
        
    }
    
    int regionsBySlashes(vector<string>& grid) {
        
        vector<vector<float>> pts;
        vector<pair<int, int>> edges;
        int count = 0;
        const int N = grid.size();
            
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (grid[i][j] == '/')
                {
                    pts.emplace_back(vector<float>({j+1, -i}));
                    pts.emplace_back(vector<float>({j, -(i+1)}));
                    edges.emplace_back(count, count+1);
                    count += 2;
                }
                else if (grid[i][j] == '\\')
                {
                    pts.emplace_back(vector<float>({j, -i}));
                    pts.emplace_back(vector<float>({j+1, -(i+1)}));
                    edges.emplace_back(count, count+1);
                    count += 2;
                }
            }
        }
        
        vector<vector<float>> corners = {{0, 0}, {N, 0}, {N, -N}, {0, -N}};

        auto pts_i = gridify(pts);
        auto corners_i = gridify(corners);
        

        
        int xmin = 999999999;
        int ymin = 999999999;
        for (auto& p : corners_i)
        {
            if (p[0] < xmin)
                xmin = p[0];
            if (p[1] < ymin)
                ymin = p[1];
        }
        
        for (auto& p : pts_i)
        {
            p[0] -= xmin;
            p[1] -= ymin;
        }
        for (auto& p : corners_i)
        {
            p[0] -= xmin;
            p[1] -= ymin;
        }
        
        int xmax = 0, ymax = 0;
        for (auto& p : corners_i)
        {
            if (p[0] > xmax)
                xmax = p[0];
            if (p[1] > ymax)
                ymax = p[1];
        }
        
        vector<vector<int>> m(ymax+1, vector<int>(xmax+1, 0));
        
        for (auto const& e : edges)
        {
            const auto& a = pts_i[e.first];
            const auto& b = pts_i[e.second];
            // std::cout << "a b " << a[0] << " " << a[1] << "     " << b[0] << " " << b[1] << std::endl;
            if (a[0] == b[0])
            {
                // std::cout << "a0=b0 : "  << a[0] << " " << b[0] << std::endl;
                for (int i = min(a[1], b[1]); i <= max(a[1], b[1]); ++i)
                {
                    m[i][a[0]] = 1;
                    // std::cout << i << " ";
                }
                // std::cout << std::endl;
            }
            else
            {
                // std::cout << "a1=b1 : " << a[1] << " " << b[1] << std::endl;
                for (int i = min(a[0], b[0]); i <= max(a[0], b[0]); ++i)
                {
                    m[a[1]][i] = 1;
                    // std::cout << i << " ";
                }
                // std::cout << std::endl;
            }
        }
        
        
//         for (auto& l : m)
//         {
//             for (auto c : l)
//                 std::cout << c << " ";
//             std::cout << "\n";
//         }
//         std::cout << std::endl;
        
        int color = 10;
        for (int i = 0; i < m.size(); ++i)
        {
            for (int j = 0; j < m[0].size(); ++j)
            {
                if (spread(m, corners_i, j, i, color))
                    ++color;
            }
        }
        
        // for (auto& l : m)
        // {
        //     for (auto c : l)
        //         std::cout << c << " ";
        //     std::cout << "\n";
        // }
        // std::cout << std::endl;
        
        return color - 10;
    }
};
