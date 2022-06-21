class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int b = bricks;
        int l = ladders;
        std::priority_queue<int> q;
        int i = 0;
        for (i = 0; i < heights.size()-1; ++i) {
            
            int diff = heights[i+1]-heights[i];
            if (diff <= 0) 
                continue;
            
            q.push(diff);
            
            b -= diff;
            if (b < 0) {               
                b += q.top();
                q.pop();
                --l;
            }
            if (l < 0)
                break;
        }
        return i;
    }
};
