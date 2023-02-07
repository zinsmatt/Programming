class Solution {
public:
    
int totalFruit(vector<int>& fruits) {
        int res = 0;
        int l = 0;
        int last_a = 0;
        int last_b = 0;
        while (l < fruits.size()) {
            int a = fruits[l];
            last_a = l;
            int i = l+1;
            while (i < fruits.size() && fruits[i] == a) {
                last_a = i;
                ++i;
            }
            res = max(res, i-l);

            if (i >= fruits.size())
                break;
    
            last_b = i;
    
            int b = fruits[i];
            while (i < fruits.size() && (fruits[i] == a || fruits[i] == b)) {
                if (fruits[i] == a)
                    last_a = i;
                if (fruits[i] == b)
                    last_b = i;
                ++i;
            }
            res = max(res, i-l);

            if (i >= fruits.size()) {
                break;
            }
            l = min(last_a, last_b) + 1;
        }
        return res;
    }
};
