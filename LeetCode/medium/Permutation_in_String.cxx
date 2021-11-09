class Solution {
  
    vector<int> hash(const std::string& s)
    {
        vector<int> h(26, 0);
        for (auto c : s)
        {
            h[c-'a']++;
        }
        return h;
    }

public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash_1 = hash(s1);
        vector<int> x(26, 0);
        int i = 0, left = 0;
        for (int i = 0; i < s2.size(); ++i)
        {
            x[s2[i]-'a']++;
            if (x[s2[i]-'a'] > hash_1[s2[i]-'a'])
            {
                while (s2[left] != s2[i])
                {
                    x[s2[left]-'a']--;
                    left++;
                }
                
                x[s2[left]-'a']--;
                left++;
            }
            else
            {
                if (x == hash_1)
                    return true;
            }
        }
        return false;
    }
};
