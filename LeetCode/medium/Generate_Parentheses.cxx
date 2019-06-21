class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::stack<std::string> s;
        std::stack<int> p;
        s.push("(");
        p.push(1);
        std::vector<std::string> ok;
        while (s.size() > 0)
        {
            auto cur = s.top();
            s.pop();
            auto curp = p.top();
            p.pop();
            
            if (cur.size() == 2*n-1)
            {
                if (curp == 1)
                {
                    cur += ")";
                    ok.push_back(cur);
                
                }
                continue;
            }
            
            
            if (curp >= 0 and curp <= n)
            {
                if (curp < n)
                {
                    // append '('
                    std::string cur_copy = cur;
                    cur_copy += "(";
                    s.push(cur_copy);
                    p.push(curp+1);
                }
                
                if (curp > 0)
                {
                    // append ')'
                    std::string cur_copy = cur;
                    cur_copy += ")";
                    s.push(cur_copy);
                    p.push(curp-1);
                }
            }
        }
        return ok;
    }
};