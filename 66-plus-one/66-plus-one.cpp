class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        reverse(digits.begin(), digits.end());
        for(auto &x: digits)
        {
            cout<<carry<<" "<<x<<endl;
            x+=carry;
            cout<<carry<<" "<<x<<endl;
            if(x>9) {
                carry = x-9;
                x = 0;
            }
            else {
                carry = 0;
            }
        }
        if(carry)
            digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};