class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1.size() > str2.size())
            swap(str1, str2);

        for (int i = str1.size(); i >= 1; --i) {
            if (str1.size() % i == 0 && str2.size() % i == 0) {
                bool ok = true;
                for (int k = 0; k < str1.size(); ++k) {
                    if (str1[k] != str1[k % i]) {
                        ok = false;
                        break;
                    }
                }

                if (!ok)
                    continue;

                for (int k = 0; k < str2.size(); ++k) {
                    if (str2[k] != str1[k % i]) {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    return str1.substr(0, i);
            }
        }
        return "";        
    }
};
