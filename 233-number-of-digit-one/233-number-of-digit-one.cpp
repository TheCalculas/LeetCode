class Solution {
public:
    int countDigitOne(int n) {
		if (n <= 0) return 0;
        if (n < 10) return 1;
		int m = n, pow = 1;
		while (m >= 10) pow *= 10, m /= 10;
		int fst = m, last = n - fst*pow; 
		return ((fst == 1)?last + 1:pow) + countDigitOne(last) + fst * countDigitOne(pow-1);
    }
};