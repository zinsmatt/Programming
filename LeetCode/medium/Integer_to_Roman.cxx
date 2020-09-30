class Solution {
public:
    string intToRoman(int n) {
        auto m = n / 1000;
        string s="";
        for (int i = 0; i < m; ++i) s+="M";
        n -= m* 1000;
        
        if (n >= 900)
        {
            s+="CM";
            n -= 900;
        }
        
        if (n >= 500)
        {
            s+="D";
            n -= 500;
        }
        
        if (n>=400)
        {
            s+="CD";
            n -= 400;
        }
        
        if (n >= 100)
        {
            auto c = n / 100;
            for (int  i = 0; i < c; ++i) s+="C";
            n -= c * 100;
        }
        
        if (n >= 90)
        {
            s+="XC";
            n -= 90;
        }
        
        if (n >= 50)
        {
            s+="L";
            n -= 50;
        }
        
        if (n >= 40)
        {
            s+="XL";
            n -= 40;
        }
        
        if (n >= 10)
        {
            auto x = n / 10;
            for (int i = 0; i < x; ++i) s+="X";
            n -= x * 10;
        }
        
        if (n >= 9)
        {
            s+="IX";
            n -= 9;
        }
        
        if (n >= 5)
        {
            s+="V";
            n -= 5;
        }
        
        if (n >= 4)
        {
            s+="IV";
            n -= 4;
        }
        
        for (int i = 0; i < n; ++i) s += "I";
        return s;
    }
};
