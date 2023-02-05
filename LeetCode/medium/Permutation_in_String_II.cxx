class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> ref(26, 0);
        for (auto c : s1)
            ++ref[c-'a'];

        vector<int> cur(26, 0);
        for (int i = 0; i < s1.size() && i < s2.size(); ++i) {
            ++cur[s2[i]-'a'];
        }
        if (cur == ref)
            return true;
        
        int i = 0;
        while (i + s1.size() < s2.size()) {
            --cur[s2[i]-'a'];
            ++cur[s2[i+s1.size()]-'a'];
            ++i;
            if (cur == ref)
                return true;
        }
        return false;
    }
};
