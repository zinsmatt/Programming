class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < firstList.size() && j < secondList.size())
        {
            if (firstList[i][0] > secondList[j][1])
            {
                ++j;
            }
            else if (firstList[i][1] < secondList[j][0])
            {
                ++i;                
            }
            else
            {
                res.push_back({std::max(firstList[i][0], secondList[j][0]), std::min(firstList[i][1], secondList[j][1])});
                if (firstList[i][1] > secondList[j][1])
                    ++j;
                else
                    ++i;
            }
        }
        return res;        
    }
};
