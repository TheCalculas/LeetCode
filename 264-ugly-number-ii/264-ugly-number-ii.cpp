class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=1){return n;}
        int k[n];
        k[0]=1;
        int c2=0, c3=0, c5=0;
        for(int i=1;i<n;i++){
            k[i]=min(k[c2]*2,min(k[c3]*3, k[c5]*5));
            if(k[i]==k[c2]*2){c2++;}
            if(k[i]==k[c3]*3){c3++;}
            if(k[i]==k[c5]*5){c5++;}
        }
        return k[n-1];
    }
};