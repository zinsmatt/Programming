class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        else if (needle.size() > haystack.size())
            return -1;
        else
        {
            for (int i = 0; i <= haystack.size() - needle.size(); ++i)
            {
                int a = i;
                int b = 0;
                while (b < needle.size() && haystack[a] == needle[b])
                {
                    ++a;
                    ++b;
                }
                if (b == needle.size())
                    return i;
            }
            return -1;            
        }
    }
};