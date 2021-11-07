class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while (i < s.size())
        {
            int j = i+1;
            while (j < s.size() && s[j] != ' ')
                ++j;
            auto w = s.substr(i, j-i);
            std::reverse(s.begin()+i, s.begin()+j);
            i = j+1;
        }
        return s;
    }
};
