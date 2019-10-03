class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        for (const auto& w : words)
        {
            stringstream ss;
            for (auto const& c : w)
            {
                ss << tab[c - 'a'];
            }
            s.insert(ss.str());
        }
        return s.size();
    }
    
    vector<string> tab = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
};
