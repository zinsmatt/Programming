class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0, b = numbers.size() - 1;
        
        while (numbers[a] + numbers[b] != target)
        {
            if (numbers[a] + numbers[b] < target)
                ++a;
            else
                --b;
        }
        return std::vector({a+1, b+1});
    }
};