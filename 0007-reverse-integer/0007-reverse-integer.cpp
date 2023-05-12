class Solution {
public:
    int reverse(int x) {
        long a = 0;
        bool flag = (x<0) ?true: false;
        x = abs(x);
        while(x>9)
        {
            a += x%10;
            a = a*10;
            x = x/10;
        }
        // a/=10;
        a += x%10;
        if(flag) a = -a;
        if(a>INT_MAX||a<INT_MIN) return 0;
        return a;
    }
};