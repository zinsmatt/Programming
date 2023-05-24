class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums2[a] > nums2[b];
        });

        priority_queue<int, vector<int>, std::greater<int>> pq;

        long long total = 0;
        long long res = 0;
        for (auto idx : indices) {
            int x1 = nums1[idx];
            int x2 = nums2[idx];

            pq.push(x1);
            total += x1;

            if (pq.size() > k) {
                total -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                res = max(res, total * x2);
            }
        }
        return res;
    }
};
