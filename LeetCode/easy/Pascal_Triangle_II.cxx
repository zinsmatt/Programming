class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> l = {1};
        for (int i = 0; i < rowIndex; ++i)
        {
            vector<int> l2(l.size() + 1);
            l2.front() = 1;
            l2.back() = 1;
            for (int j = 1; j < l2.size() - 1; ++j)
            {
                l2[j] = l[j] + l[j-1];
            }
            l = l2;
        }
        return l;
    }
};