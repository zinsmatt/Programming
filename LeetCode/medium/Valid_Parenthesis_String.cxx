class Solution {
public:
    bool checkValidString(string s) {
        
        stack<pair<char, int>> st;
        int b = 0;
        for (auto c  : s)
        {
            if (c == '(')
            {
                st.push({'(', 0});
            }
            else if (c == '*')
            {
                if (st.size() == 0)
                    b++;
                else
                    st.top().second++;
            }
            else
            {
                if (st.size() == 0)
                {
                    if (b > 0)
                        --b;
                    else
                        return false;
                }
                else
                {
                    int nb = st.top().second;
                    st.pop();
                    if (st.size() > 0)
                        st.top().second += nb;
                    else
                        b += nb;
                }
            }
        }
        
        while (st.size() > 0)
        {
            int nb = st.top().second;
            if (nb == 0)
                return false;
            st.pop();
            if (st.size() > 0)
            {
                st.top().second += nb-1;
            }
        }
        return true;
    }
};
