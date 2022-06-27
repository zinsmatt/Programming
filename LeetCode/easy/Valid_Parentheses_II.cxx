class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (auto c : s) {
            if (st.size() == 0) st.push(c);
            else if (st.top() == '(' && c == ')' ||
                     st.top() == '{' && c == '}' ||
                     st.top() == '[' && c == ']')
                st.pop();
            else
                st.push(c);
        }
        return st.size() == 0;        
    }
};
