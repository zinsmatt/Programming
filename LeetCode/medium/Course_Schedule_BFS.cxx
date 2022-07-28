class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> req(n, vector<int>());
        for (auto & p : prerequisites) {
            req[p[0]].push_back(p[1]);
        }

        
        // Kahn's algorithm
        vector<int> indegrees(n, 0);
        for (auto &p : prerequisites) {
            ++indegrees[p[1]];            
        }
        
        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegrees[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            count++;
            for (auto e : req[x]) {
                indegrees[e]--;
                if (indegrees[e] <= 0)
                    q.push(e);
            }
        }
        return count == n;        
    }
};


