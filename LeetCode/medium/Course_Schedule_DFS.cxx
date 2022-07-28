class Solution {
    vector<vector<int>> req;
    vector<bool> explored;
    
    bool find_loop(int x, vector<bool> path) {       
        if (path[x])
            return true;

        path[x] = true;
        explored[x] = true;
        
        for (auto e : req[x]) {
            if (explored[e]) {
                if (path[e])
                    return true;
            } else {
                auto res = find_loop(e, path);
                if (res)
                    return true;
            }
        }
        return false;
    }

    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        req.resize(n, vector<int>());
        for (auto & p : prerequisites) {
            req[p[0]].push_back(p[1]);
        }
        
        explored.resize(n, false);
        for (int i = 0; i < n; ++i) {
            if (!explored[i]) {
                auto loop = find_loop(i, vector<bool>(n, false));
                if (loop)
                    return false;
            }
        }
        return true;    
    }
};


