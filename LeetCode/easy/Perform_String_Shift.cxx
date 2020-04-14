class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int a = 0;
        for(const auto& sh : shift)
        {
            a = (a + (static_cast<int>(pow(-1, sh[0])) * sh[1])) % static_cast<int>(s.size());
            if (a < 0)
                a += s.size();
        }
        string res = "";
        res = s.substr(a) + s.substr(0, a);
        return res;
    }
};
