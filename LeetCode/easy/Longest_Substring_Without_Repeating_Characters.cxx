class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        std::unordered_set<char> arr;
        int a = 0;
        int b = 0;
        int max = 0;
        while (b < s.size())
        {
            if (arr.find(s[b]) == arr.end())
            {
                arr.insert(s[b]);
                b++;
            }
            else
            {
                if (b-a > max)
                    max = b-a;
                while (s[a] != s[b])
                {
                    arr.erase(s[a]);
                    ++a;
                }
                ++a;
                ++b;
            }
                
        }
        if (b - a > max)
            max = b - a;
        return max;
    }
