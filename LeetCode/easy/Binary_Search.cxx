class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bin(nums, 0, nums.size()-1, target);
    }
    int bin(vector<int>& arr, int a, int b, int t)
    {
        if (a == b)
        {
            if (arr[a] == t)
                return a;
            else
                return -1;
        }
        else if (a > b)
        {
            return -1;
        }
        else
        {
            int m = (a + b) / 2;
            if (arr[m] > t)
                return bin(arr, a, m, t);
            else if (arr[m] < t)
                return bin(arr, m+1, b, t);
            else
                return m;
        }
    }
};