class Solution {
public:
    int climbStairs(int n) {
vector<long> ways(n+2, 0);
ways[0] = 1;
for (int i = 0; i < n; ++i) {
	ways[i+1] += ways[i];
	ways[i+2] += ways[i];
}
return ways[n];	
    }
};

