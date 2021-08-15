class Solution {
    unordered_map<char, int> m;
    bool good()
    {
        bool ok = true;
        for (auto it : m)
        {
            if (it.second < 0) ok = false;
        }
        
        return ok;
    }

public:
    string minWindow(string s, string t) {
        
        
        for (auto c : t)
            m[c] = 0;
        for (auto c : t)
            m[c]--;
        
        int l = 0, r = 0;
        m[s[r]]++;
        
        int ll=-1, rr=-1, ss=std::numeric_limits<int>::max();
        while (r < s.size())
        {
            while (r < s.size() && !good())
            {
                ++r;
                if (r < s.size())
                    m[s[r]]++;
            }
            
            if (r >= s.size())
                break;

            
            if (r-l+1 < ss)
            {
                ss = r-l+1;
                ll = l;
                rr = r;
            }
        
            while (l <= r && good())
            {
                m[s[l++]]--;
            }
            
            if (r-(l-1)+1 < ss)
            {
                ss = r-(l-1)+1;
                ll = l-1;
                rr = r;
            }
        }
        if (ll == -1 || rr == -1) return "";
        return s.substr(ll, rr-ll+1);
    }
};
