class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> ab(26, 0);
        for (auto c : chars)
        {
            ++ab[c - 'a'];
        }
        
        int res = 0;
        for (auto& w : words)
        {
            auto abc = ab;
            bool ok = true;
            for (auto c : w)
            {
                if (abc[c - 'a'] == 0)
                {
                    ok = false;
                    break;
                }
                else
                    --abc[c - 'a'];
            }
            if (ok)
                res += w.size();
        }
        return res;
    }
};