class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        for(int i=0; i<100; i++)
        {
            count += n&1;
            n >>= 1;
        }
        return (count==1)?true:false;
    }
};