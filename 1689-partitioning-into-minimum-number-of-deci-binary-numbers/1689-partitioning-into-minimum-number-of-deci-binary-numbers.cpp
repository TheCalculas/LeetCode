class Solution {
public:
      int minPartitions(string n) {
          // return the maximum element yaar easy tha bc ye toh
          
        return *max_element(begin(n), end(n)) - '0';
    }
};