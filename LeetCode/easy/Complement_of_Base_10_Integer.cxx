class Solution {
public:
    int bitwiseComplement(int N) {
        int res = 0;
        int q = N;
        std::vector<int> temp;
        while (q > 0)
        {
            int r = q % 2;
            q = (q - r) / 2;
            temp.push_back((r + 1) % 2);
        }
        if (temp.size() == 0)
            return 1;
        for (int i = 0; i < temp.size(); ++i)
        {
            std::cout << temp[i] << " ";
            res += std::pow(2, i) * temp[i];
        }
        return res;
    }
};