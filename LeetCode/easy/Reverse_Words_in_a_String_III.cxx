class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        vector<string> words;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                if (ss.str().size() > 0)
                {
                    words.push_back(ss.str());
                    ss.str("");
                    ss.clear();
                }
            }
            else
            {
                ss << s[i];
            }
        }
        if (ss.str().size() > 0)
            words.push_back(ss.str());
        ss.str("");
        ss.clear();
        for (auto& w : words)
        {
            reverse(w.begin(), w.end());
            ss << w << " ";
        }
        auto res = ss.str();
        return res.substr(0, res.size() - 1);
    }
};