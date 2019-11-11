class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int x = 0;
        stack<int> s;
        for (int i = 0; i < seq.size(); ++i)
        {
            if (seq[i] == ')')
            {
                int pred = s.top();
                s.pop();
                res.push_back(pred);
                x = pred;
            }
            else
            {
                s.push(x);
                res.push_back(x);
                x = (x + 1) % 2;
            }
        }
        return res;        
    }
};