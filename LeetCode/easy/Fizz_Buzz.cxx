class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n, "");
        for (int i = 0; i < n; ++i) {
            int j = i+1;
            if (j % 3 == 0 && j % 5 == 0)
                res[i] = "FizzBuzz";
            else if (j% 3 == 0)
                res[i] = "Fizz";
            else if (j % 5 == 0)
                res[i] = "Buzz";
            else
                res[i] = std::to_string(j);
        }
        return res;
    }
};
