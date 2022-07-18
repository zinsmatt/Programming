class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	std::unordered_set<char> m;
	int i = 0, j = 0;
    int res = 0;
	while (j < s.size()) {
		while (j < s.size() && m.count(s[j]) == 0) {
			m.insert(s[j]);
            ++j;
            res = std::max(res, (int)m.size());
		}
		if (j < s.size()) {
			while (i <= j && m.count(s[j])) {
				m.erase(s[i]);
				++i;
            }
		}
	}
	return res;        
    }
};

