class Solution {
public:
    int bin_grey(int n1){
        int shift=int(log(n1)/log(2));
        long n=n1;
        long num=((n>>shift)&(1));
        for(int i=shift;i>=1;i--){
            int move=shift-i;
            long long n1=((n>>i) & (1));
            long long n2=((n>>(i-1))&(1));
            
            num=((num<<1)+(n1^n2));
        }
        return num;
    }
    vector<int> grayCode(int n) {
        vector<int>v;
        v.push_back(0);
        for(int i=1;i<pow(2,n);i++){
            v.push_back(bin_grey(i));
        }
        return v;
    }
};