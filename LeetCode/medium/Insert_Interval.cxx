class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	int i = 0;
	vector<vector<int>> res;
    bool done = false;
	for (int i = 0; i < intervals.size(); ++i) {
		if (intervals[i][0] > newInterval[1]) {
			if (!done)
    			res.push_back(newInterval);
            done = true;
			res.push_back(intervals[i]);
		} else if (intervals[i][1] < newInterval[0]) {
			res.push_back(intervals[i]);
        } else {
	        newInterval[0] = std::min(newInterval[0], intervals[i][0]);
	        newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        }
    }
    if (!done)
	    res.push_back(newInterval);
    return res;
}

};


