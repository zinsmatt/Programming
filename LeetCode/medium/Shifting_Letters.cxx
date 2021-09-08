class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long count = 0;
        for (int i = shifts.size()-1; i >= 0; --i)
        {
            count += shifts[i];
            
            long long a = s[i]-'a';
            a = (a + count) % 26;
            char c = 'a' + a;
            s[i] = c;
        }
        return s;        
    }
};
