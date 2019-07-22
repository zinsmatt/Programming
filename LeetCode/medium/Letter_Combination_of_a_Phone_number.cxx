class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
        {
            return vector<string>();
        }
        vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<int> digits_i(digits.size());
        
        vector<int> sizes(digits.size(), 0);
        int total = 1;
        for (int i = 0; i < digits.size(); ++i)
        {
            digits_i[i] = static_cast<int>(digits[i]-'2');
            int r = map[digits_i[i]].size();
            sizes[i] = r;
            total *= r;            
        }
        vector<stringstream> arr(total);
        int repeat = 1;
        for (int i = 0; i < digits.size(); ++i)
        {
            int j = 0;
            int c = 0;
            while (j < total)
            {
                
                int k = 0;
                for (int z = 0; z < repeat; ++z)
                {
                    arr[j++] << map[digits_i[i]][c];
                }
                c = (c + 1) % sizes[i];
            }
            repeat *= sizes[i];
        }
        
        vector<string> res(total);
        for (int i = 0; i < total; ++i)
        {
            res[i] = arr[i].str();
        }
        return res;
    }
};