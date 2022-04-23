class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> a(n), b(n);
        int p = 0;
        int aa = 0, bb = 0;
        for (auto x : nums) {
            if (x < pivot) {
                a[aa++] = x;
            } else if (x > pivot) {
                b[bb++] = x;
            } else
                p++;
        }
        cout << "\n";
        vector<int> out(n);
        int i = 0;
        while (i < aa) {
            out[i] = a[i];
            ++i;
        }
        for (int j = 0; j < p; ++j)
            out[aa+j] = pivot;
        i = 0;
        while (i < bb) {
            out[i+aa+p] = b[i];
            ++i;
        }
        return out;
    }
};
