class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        vector<string> words;
        while (i < s.size())
        {

            while (i < s.size() && s[i] == ' ')
            {
                ++i;
            }
            int j = i;
            while (j < s.size() && s[j] != ' ')
            {
     
                ++j;
            }
            if (i < s.size())
            {
                words.push_back(s.substr(i, j-i));
                i = j;
            }
            
        }
        stringstream out;
        reverse(words.begin(), words.end());
        for (int i = 0; i < words.size(); ++i)
        {
            //std::cout << "|" << words[i] << "|\n";
            out << words[i];
            if (i < words.size()-1)
            {
                out << " ";
            }
        }
        return out.str();
    }
};
