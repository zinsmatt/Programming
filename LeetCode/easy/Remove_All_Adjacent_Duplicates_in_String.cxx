class Solution {
public:
    string removeDuplicates(string S) {
        std::stack<char> s;
        for (auto& c : S)
        {
            if (s.size() > 0 && s.top() == c)
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
        }
        std::stringstream ss;
        while (!s.empty())
        {
            ss << s.top();
            s.pop();
        }
        std::string res = ss.str();
        std::reverse(res.begin(), res.end());
        return res;        
    }
};