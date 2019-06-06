class Solution {
public:
    bool isValid(string s) {
        std::stack<int> st;
        for (auto& c : s)
        {
            int x;
            switch(c)
            {
                case '(':
                    x = 1;
                    break;
                case '{':
                    x = 2;
                    break;
                case '[':
                    x = 3;
                    break;
                 case ')':
                    x = -1;
                    break;
                case '}':
                    x = -2;
                    break;
                case ']':
                    x = -3;
                    break;
            }
            if (st.empty())
                st.push(x);
            else
            {
                if (st.top() + x == 0)
                    st.pop();
                else
                    st.push(x);
            }
        }
        return st.empty();
    }
};