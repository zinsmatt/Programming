class Solution {
public:
    int binaryGap(int N) {
        int max = 0;
        int q = N;
        int last = -1;
        int i = 0;
        while (q > 0)
        {
            int new_q = q / 2;
            int r = q -  2 * new_q;
            if (r == 1)
            {
                if (last >= 0)
                {
                    if (i - last > max)
                        max = i - last;
                }
                last = i;
            }
            q = new_q;
            ++i;
        }
        return max;
    }
};