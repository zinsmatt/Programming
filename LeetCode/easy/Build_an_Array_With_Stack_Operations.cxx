class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> cmd;
        int res = 0;
        int i = 1;
        while (res < target.size())
        {
            cmd.push_back("Push");
            if (target[res] != i)
                cmd.push_back("Pop");
            else
                res++;
            i++;
        }
        return cmd;
        
    }
};
