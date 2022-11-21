class Solution {
    bool is_exit(int w, int h, int x, int y) {
        return x == 0 || y == 0 || x == w-1 || y == h-1;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int w = maze[0].size();
        int h = maze.size();
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';


        while (q.size()) {
            auto p = q.front();
            // std::cout << p[0] << " " << p[1] << " " << p[2] << std::endl;
            q.pop();

            int s = p[2];
            if (s > 0 && is_exit(w, h, p[1], p[0])) {
                return s;
            }
            ++s;
            if (p[0] > 0 && maze[p[0]-1][p[1]] == '.')
            {
                maze[p[0]-1][p[1]] = '+';
                q.push({p[0]-1, p[1], s});
            }
            if (p[1] > 0 && maze[p[0]][p[1]-1] == '.')
            {
                maze[p[0]][p[1]-1] = '+';
                q.push({p[0], p[1]-1, s});
            }
            if (p[0] < h-1 && maze[p[0]+1][p[1]] == '.')
            {
                maze[p[0]+1][p[1]] = '+';
                q.push({p[0]+1, p[1], s});
            }
            if (p[1] < w-1 && maze[p[0]][p[1]+1] == '.')
            {
                maze[p[0]][p[1]+1] = '+';
                q.push({p[0], p[1]+1, s});
            }
        }
        return -1;
    }
};
