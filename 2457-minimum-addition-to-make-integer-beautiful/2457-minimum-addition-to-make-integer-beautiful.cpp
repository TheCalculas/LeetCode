class Solution {
public:
    int sumDig(long long n)
    {
        int res = 0;
        while(n)
        {
            res += n%10;
            n/=10;
        }
        return res;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        long long ans = 0;
        long long mul = 1;
        while(sumDig(n)>target)
        {
            auto lastVal = n%10;
            auto req = 10 - lastVal;
            ans += mul * req;
            n = n/10;
            n++;
            mul= mul*10;
        }
        return ans;
    }
};