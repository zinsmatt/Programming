class Solution {
    
    bool not_op(char c)
    {
        return c != '*' && c != '-' && c !='/' && c != '+';
    }
    int compute(int a, int b, char op)
    {
        if (op == '+') return a+b;
        if (op == '/') return a/b;
        if (op == '-') return a-b;
        if (op == '*') return a*b;
        return 0;
    }
    
    
public:
    int calculate(string s) {
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == '*' || s[i] == '/')
            {
                int l = i-1;
                while (l >= 0 && not_op(s[l]))
                    --l;
                int r = i+1;
                while (r < s.size() && not_op(s[r]))
                    ++r;
                
                int ll = std::stoi(s.substr(l+1, i-l));
                int rr = std::stoi(s.substr(i+1, r-i));
                auto x = compute(ll, rr, s[i]);
                
                std::string nouv_s = std::to_string(x);
                if (l >= 0)
                {
                    nouv_s = s.substr(0, l+1) + nouv_s;
                }
                
                if (r < s.size())
                {
                    nouv_s = nouv_s + s.substr(r);
                }
                s = nouv_s;
                i = 0;
             }
            ++i;
        }
        
      
        
        
        int res = 0;
        i = 0;
        while (i < s.size())
        {
            int sign = 1;
            int l = i;
            if (s[i] == '-') sign *= -1;
            else if (s[i] == '+') sign = 1 * sign;
            if (s[i] == '-' || s[i] == '+')
                l = i+1;
            
            int r = i+1;
            while (r < s.size() && not_op(s[r]))
                ++r;
            int x = std::stoi(s.substr(l, r-l+1));
            x *= sign;
            res += x;  
            i = r;
        }
        
        
        
        return res;
    }
};
