class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        std::vector<int> arr;
        int r = x, q = x;
        while (q != 0)
        {
            arr.push_back(q % 10);
            q = q / 10;   
        }
        auto it1 = arr.begin();
        auto it2 = arr.rbegin();
        for (;it1 != arr.end() && it2 != arr.rend();
            ++it1, ++it2)
        {
            if (*it1 != *it2)
                return false;
        }
        return true;
    }
};