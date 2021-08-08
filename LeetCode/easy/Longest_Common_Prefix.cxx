class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        bool ok = true;
        while (ok)
        {
            ok = true;   
            for (auto& s : strs)
            {
                ok &= (i < s.size() && s.size()>0 && strs[0].size()>0 && s[i] == strs[0][i]);
            }
            if (ok) ++i;
        }
        return strs.front().substr(0, i);
    }
};
