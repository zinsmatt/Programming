class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0)
            return vector<int>({0});
        else if (num == 1)
            return vector<int>({0, 1});
        vector<int> res = {0, 1};
        int n = 1;
        while (res.size()-1 < num)
        {
            auto res2 = res;
            for (int j = n; j > 0; --j)
            {
                auto temp= res[res.size()-j];
                res2.push_back(temp+0);
                res2.push_back(temp+1);
            }
            res = res2;
            n *= 2;
        }
        res.resize(num+1);
        return res;
    }
};