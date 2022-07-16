class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<0) return false;
        long hi = sqrt(c);
        long lo = 0;
        while(hi>=lo)
        {
            long ans = hi*hi + lo*lo;
            cout<<ans<<endl;
            if(ans==c) return true;
            else if(ans<c) lo++;
            else hi--;
        }
        return false;
    }
};