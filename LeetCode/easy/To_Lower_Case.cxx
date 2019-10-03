class Solution {
public:
    string toLowerCase(string str) {
        int diff = 'a'-'A';
        for (auto& c : str)
        {
            if (c >= 'A' && c <= 'Z')
                c += diff;
        }
            
        return str;
    }
};
