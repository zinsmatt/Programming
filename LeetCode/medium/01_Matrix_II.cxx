class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
	vector<vector<int>> dists(mat.size(), vector<int>(mat[0].size(), std::numeric_limits<int>::max()));
	int i0 = -1, j0 = -1;
    std::queue<pair<pair<int, int>, int>> q;

	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat[0].size(); ++j) {
			if (mat[i][j] == 0) {
				i0 = i;
				j0 = j; 
                q.push({{i, j}, 0});
            }
        }
    }
        

				
			

            q.push({{i0, j0}, 0});
			while (!q.empty()) {
				auto [coord, c] = q.front();
                int x = coord.first;
                int y = coord.second;
				q.pop();
				
				if (dists[x][y] <= c)
					continue;

				dists[x][y] = c;
				c += 1;
				if (x > 0)
                    q.push({{x-1, y}, c});
                if (x < mat.size()-1)
                    q.push({{x+1, y}, c});
                if (y > 0)
                    q.push({{x, y-1}, c});
                if (y < mat[0].size()-1)
                    q.push({{x, y+1}, c});				
			}

return dists;
        
    }
};


