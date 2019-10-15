class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words, res;
        stringstream ss;
        for (int i = 0; i < text.size(); ++i)
        {
            if (text[i] == ' ')
            {
                if (ss.str().size() > 0)
                    words.emplace_back(ss.str());
                ss.str("");
                ss.clear();
            }
            else
            {
                ss << text[i];
            }
        }
        if (ss.str().size() > 0)
            words.emplace_back(ss.str());
        
        for (int i = 0; i < words.size() - 2; ++i)
        {
            if (words[i] == first && words[i+1] == second)
                res.emplace_back(words[i+2]);
        }
        return res;
    }
}