class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 0)
            return n == 0;
        if (flowerbed.size() == 1)
            return (flowerbed.front() == 0 && n == 1) || n == 0;
            
        int i = 0;
        while (i < flowerbed.size())
        {
            if (flowerbed[i] == 0)
            {
                bool good = false;
                if (i == 0)
                {
                    if (flowerbed[i+1] == 0)
                    {
                        good = true;   
                    }
                }
                else if (i == flowerbed.size() -1)
                {

                    if (flowerbed[i-1] == 0)
                    {
                        good = true;
                    }
                }
                else
                {
                    if (flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
                    {
                        good = true;
                    }
                }
                 
                if (good)
                {
                    flowerbed[i] = 1;
                    n--;
                    i++;
                }
            }
            ++i;
        }
        return n <= 0;
    }
};