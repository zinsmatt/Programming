class Solution {
public:
    int minAddToMakeValid(string s) {
        int r = 0, l = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                l++;
            }
            else {
                if (l == 0) {
                    res++;
                } else {
                    l--;
                }
            }
        }
        return res + l;
    }
}
