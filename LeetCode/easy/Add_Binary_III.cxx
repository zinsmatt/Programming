class Solution {
public:
    string addBinary(string a, string b) {
        stringstream res;
        int r = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        while (i >= 0 || j >= 0) {
            if (i >= 0)
                r += a[i]-'0';
            if (j >= 0)
                r += b[j]-'0';
            res << (r % 2);
            r /= 2;
            --i;
            --j;
        }
        if (r)
            res << "1";
        string out = res.str();
        reverse(out.begin(), out.end());
        return out;
    }
};
