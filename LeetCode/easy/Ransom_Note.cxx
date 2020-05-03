class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> occ(26, 0);
        for (auto c : magazine)
        {
            occ[c-'a']++;
        }
        for (auto c : ransomNote)
        {
            occ[c-'a']--;
            if (occ[c-'a'] < 0)
                return false;
        }
        return true;
        
    }
};
