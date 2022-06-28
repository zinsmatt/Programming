class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        stringstream out;
        int ret = 0;
        for (int i = 0; i < std::max(a.size(), b.size()); ++i) {
            int x = 0, y = 0;
            if (i < a.size())
                x = a[i] - '0';
            if (i < b.size())
                y = b[i] - '0';
            
            auto tot = x + y + ret;
            ret = 0;
            if (tot > 1) 
                ret = 1;
            out << std::to_string(tot % 2);
        }
        if (ret) 
            out << "1";
        std::string res = out.str();
        reverse(res.begin(), res.end());
        return res;
    }
};
