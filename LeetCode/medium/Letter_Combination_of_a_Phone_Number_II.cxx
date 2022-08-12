class Solution {
    vector<string> res;
    
    void solve(std::vector<string>& letters, int i, std::string cur) {
        if (cur.size() == letters.size()) {
            res.emplace_back(cur);
        } else {
            for (auto c : letters[i]) {
                auto cur2 = cur;
                cur2 += c;
                solve(letters, i+1, cur2);
            }
        }
    }

        
        
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters;
        for (auto& c : digits) {
            if (c == '2') letters.push_back("abc");
            if (c == '3') letters.push_back("def");
            if (c == '4') letters.push_back("ghi");
            if (c == '5') letters.push_back("jkl");
            if (c == '6') letters.push_back("mno");
            if (c == '7') letters.push_back("pqrs");
            if (c == '8') letters.push_back("tuv");
            if (c == '9') letters.push_back("wxyz");
        }
        if (letters.size())
            solve(letters, 0, "");
        return res;
    }
    
    
};
