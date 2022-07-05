class Solution {
public:
    int getMinSwaps(string num, int k) {
        auto init_num = num;
        for (int i = 0; i < k; ++i) {
            std::next_permutation(num.begin(), num.end());            
        }
        
        int res = 0;
        for (int i = 0; i < num.size(); ++i) {
            int j = i;
            while (num[i] != init_num[j]) { // permutation so no need to check bound for j
                ++j;
            }
            while (j > i) {
                std::swap(init_num[j], init_num[j-1]);
                --j;
                ++res;
            }
        }
        return res;
    }
};
