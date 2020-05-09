class Solution {
public:
    bool isPerfectSquare(int num) {
        long int i = 1;
        while (i*i < num)
            ++i;
        return i*i == num;
    }
};
