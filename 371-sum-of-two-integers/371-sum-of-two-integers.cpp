class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        
        // bigger one at first to solve minus op
        int x = abs(a);
        int y = abs(b);
        if (x < y) return getSum(b, a);
        
        // result sign, since x > y
        int sign = a > 0 ? 1 : -1;
        
        if (a * b > 0) {
            // both positive or both negtive
            while (y) {
                int rst = x ^ y;
                int carry = (x & y) << 1;
                x = rst;
                y = carry;
            }
        } else {
            // one of them is neg, cal x - y since x > y
            while (y) {
                int rst = x ^ y;
                int borrow = (~x & y) << 1;
                x = rst;
                y = borrow;
            }
        }
        return sign * x;
    }
};