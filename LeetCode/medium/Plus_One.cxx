class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int r = 1;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if (r > 0)
            {
                if (digits[i] == 9)
                {
                    digits[i] = 0;
                    r = 1;
                }
                else
                {
                    digits[i]++;
                    r = 0;
                }
            }
            else
            {
                break;
            }
        }
        if (r == 1)
        {
            std::vector<int> nouv(digits.size()+1, 0);
            nouv[0] = 1;
            std::copy(digits.begin(), digits.end(), nouv.begin()+1);
            return nouv;
        }
        else
        {
            return digits;
        }
    }
};