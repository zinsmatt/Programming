class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream cur_s;
        for (int i = 0; i < s.size(); ++i)
        {
            
            if (s[i] == ' ')
            {
                if (cur_s.str().size() > 0)
                {
                    words.emplace_back(cur_s.str());
                    cur_s.str("");
                }
            }
            else
            {
                cur_s << s[i];
            }
        }
        if (cur_s.str().size() > 0)
            words.emplace_back(cur_s.str());
        stringstream res;
        for (auto it = words.rbegin(); it != words.rend(); ++it)
        {
            res << *it << " ";
        }
        auto ret = res.str();
        if (ret.size() > 0)
            return ret.substr(0, ret.size()-1);
        else
            return ret;
    }
};