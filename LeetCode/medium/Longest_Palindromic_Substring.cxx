class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> P(1000, vector<int>(1000, 0));
        int n = s.size();
        int maxi = 1;
        int imax = 0;
  
        for (int d = 1; d <= n; ++d)
        {    
            for (int i = 0; i+d <= n; ++i)
            {
                if (d == 1)
                {
                    P[i][i] = 1;
                }
                else if (d == 2)
                {
                    if (i < n-1 && s[i] == s[i+1])
                    {
                        P[i][i+1] = 1;
                        maxi = d;
                        imax = i;
                    }
                }
                else
                {
                    if (i+d-1 < n)
                    {
                        P[i][i+d-1] = P[i+1][i+d-2] && s[i] == s[i+d-1];
                        if (P[i][i+d-1] && d > maxi)
                        {
                            maxi = d;
                            imax = i;
                        }
                    }
                }
            }
        }
        return s.substr(imax, maxi);
    }
};
