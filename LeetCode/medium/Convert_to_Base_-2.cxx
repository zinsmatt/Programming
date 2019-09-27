class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0)
            return "0";
        vector<int> arr(32, 0);
        int q = N;
        int a = 0;
        while (q > 0)
        {
            int r = q % 2;
            arr[a++] = r;
            q = (q-r) / 2;
        }
        
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] == 0)
                continue;
            int s = arr[i];
            arr[i] = s % 2;
            arr[i+1] += (s - s % 2) / 2;
            
            if (i % 2 == 1)
            {
                arr[i+1] += arr[i];
            }
        }
        
        stringstream ss;
        bool leading_zero = true;
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            if (leading_zero && arr[i] == 0)
                continue;
            leading_zero = false;
            ss << arr[i];
        }
        return ss.str();
    }
};