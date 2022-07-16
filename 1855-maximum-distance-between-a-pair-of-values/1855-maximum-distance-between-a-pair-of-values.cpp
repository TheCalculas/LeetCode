class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // areh bc ye toh easy hai 
        int n = nums1.size();
        int m = nums2.size();
        int i =0;
        int j = 0;
        int mx = 0;
        while(i<n&&j<m)
        {
            if(nums1[i]>nums2[j]) i++;// kyyoki apne ko bada chaihnhyeee
            else{
                mx = max(mx, j-i);
                j++;
            }
        }
        return mx;
    }
};