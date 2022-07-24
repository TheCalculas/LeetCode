class Solution {
public:
    int mySqrt(int x) {
        
    long long int l=1;
    long long int h=x;
    while(l<=h)
    {
        long long int mid=l+(h-l)/2;
        if(mid*mid==x)
        {
            h=mid;
            break;
        }
        else if(mid*mid>x)
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

        return h;
    }
};