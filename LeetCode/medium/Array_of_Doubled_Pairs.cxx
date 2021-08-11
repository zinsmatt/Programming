class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        unordered_map<int, int> v;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (v.find(arr[i]) == v.end())
            {
                if (v.find(arr[i]*2) == v.end())
                    v[arr[i]*2] = 1;
                else
                    v[arr[i]*2] += 1;
            }
            else
            {
                v[arr[i]]--;
                if (v[arr[i]] == 0)
                    v.erase(arr[i]);
            }
        }
        return v.size() == 0;
    }
};
