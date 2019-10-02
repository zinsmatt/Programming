class Solution {
public:
    string removeOuterParentheses(string S) {
        stringstream ss;
        int state = 0;
        int count = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            if (state == 0 && S[i] == '(')
            {
                state = 1;
                count = 0;
                continue;
            }
            if (count == 0 && S[i] == ')')
            {
                state = 0;
                continue;
            }
            
            ss << S[i];
            if (S[i] == '(')
                count++;
            else
                count--;
        }
        return ss.str();
        
    }
};
