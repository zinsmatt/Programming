class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> map;
        for (auto& c : J)
            map[c] = 0;
        int res = 0;
        for (auto& c : S)
        {
            if (map.find(c) != map.end())
            {
                ++res;
            }
        }
        return res;
    }
};
