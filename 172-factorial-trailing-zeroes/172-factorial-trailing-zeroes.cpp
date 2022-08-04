class Solution {
public:
    int trailingZeroes(int n) {
        long long ans = 0;
        long long five = 5;
        while(n/five)
        {
            ans += n/five;
            five = five * 5;
        }
        return ans;
    }
};