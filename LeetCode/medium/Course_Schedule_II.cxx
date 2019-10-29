class Solution {
public:
    
    vector<vector<int>> pre;
    vector<bool> done;
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        pre.resize(numCourses);
        done.resize(numCourses);
        for (auto& p : prerequisites)
        {
            pre[p[0]].push_back(p[1]);
        }
        
        
        for (int i = 0; i < numCourses; ++i)
        {
            if (!done[i])
            {
                vector<bool> loop(numCourses, false);
                if (!solve(i, loop))
                {
                    return vector<int>();
                }
            }
        }
        return res;
    }
    
    bool solve(int i, vector<bool>& loop)
    {
        loop[i] = true;
        for (auto p : pre[i])
        {
            if (!done[p])
            {
                if (loop[p])
                    return false;
                if (!solve(p, loop))
                    return false;
            }
        }
        done[i] = true;
        res.push_back(i);
        return true;
    }
};