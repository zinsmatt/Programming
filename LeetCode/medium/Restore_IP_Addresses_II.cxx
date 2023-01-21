class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12)
            return {};
        vector<string> out;
        for (int i = 1; i <= 3; ++i) {
            for (int j = i+1; j <= i+3 && j < s.size() - 1; ++j) {
                for (int k = j+1; k <= j+3 && k < s.size(); ++k) {
                    // cout << "ijk " << i << j << k << "\n";

                    if (s[0] == '0' && i != 1)
                        continue;
                    if (s[i] == '0' && j != i+1)
                        continue;
                    if (s[j] == '0' && k != j+1)
                        continue;
                    if (s[k] == '0' && k+1 != s.size())
                        continue;


                    
                    // cout << s.substr(0, i) << "\n";
                    // cout << s.substr(i, j-i) << "\n";
                    // cout << s.substr(j, k-j) << "\n";
                    // cout << s.substr(k, s.size()-k) << "\n";
                    if (stoi(s.substr(0, i)) > 255)
                        continue;
                    if (stoi(s.substr(i, j-i)) > 255)
                        continue;
                    if (stoi(s.substr(j, k-j)) > 255)
                        continue;
                    if (stoi(s.substr(k, s.size()-k)) > 255)
                        continue;
                    stringstream ss;
                    for (int a = 0; a < s.size(); ++a) {
                        if (a == i || a == j || a ==k)
                            ss << ".";
                        ss << s[a];
                    }
                    out.push_back(ss.str());
                }
            }
        }
        return out;
    }
};
