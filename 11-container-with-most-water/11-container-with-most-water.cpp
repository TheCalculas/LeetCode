class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0; 
        int j = height.size()-1;
        // kya mei ise 2 pointer se kar sakta hu lmao
        int area = 0;
        while(i<=j)
        {
            area = max(area, min(height[i], height[j])*(j-i));
            if(height[i]>height[j])j--;
            else i++;
        }
        return area;
        
    }
};