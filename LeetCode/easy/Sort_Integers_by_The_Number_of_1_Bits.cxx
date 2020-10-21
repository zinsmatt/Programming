int count(int x)
{
    int a = 0;
    while (x > 0)
    {
        auto r = x % 2;
        a += r;
        x = (x - r) / 2;
    }
    return a;
}

class Solution {
public:
    

    
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            auto ca = count(a);
            auto cb = count(b);
            if (ca == cb)
                return a < b;
            else
                return ca < cb;
        });
        return arr;
    }
}
