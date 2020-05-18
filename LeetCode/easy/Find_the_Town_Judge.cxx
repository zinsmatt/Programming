class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> t(N, 0);
        vector<int> d(N, 0);
        for (auto& p : trust){
            t[p[1]-1]++;
            d[p[0]-1]++;  
            
        }
        int i = 0;
        while (i < N)
        {
            if (t[i] == N-1 && d[i] == 0)
                return i+1;
            ++i;
        }
        return -1;
        
    }
};
