class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (1) {
            int found = -1;
            for (int i = 0; i < s.size(); ++i) {
                if (s.substr(i, part.size()) == part) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                s = s.substr(0, found) + s.substr(found + part.size());
            } else {
                return s;
            }
        }
    }
};
