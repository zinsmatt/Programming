class Solution {
public:
    string defangIPaddr(string address) {
        stringstream ss;
        for (auto const& c : address)
        {
            if (c == '.')
            {
                ss << "[.]";
            }
            else
                ss << c;
        }
        return ss.str();
    }
};
