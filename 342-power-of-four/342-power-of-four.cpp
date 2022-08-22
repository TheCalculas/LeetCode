class Solution {
public:
    // int mod = 10e9+7;
    bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}
};