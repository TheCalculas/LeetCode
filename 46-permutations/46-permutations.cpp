class Solution {
public:
    
    void permuteAll(vector<int>nums, vector<int> &ans, vector<int> &vis, vector<vector<int>>&output)
    {
        if(ans.size()==nums.size())
        {
            output.push_back(ans);
            return;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            
            int a = nums[i];
            if(!vis[i])
            {
                vis[i]=1;
                ans.push_back(a);
                permuteAll(nums, ans, vis, output);
                ans.pop_back();
                vis[i]=0;
             }
                
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> output;
        vector<int> vis(n,0);
        vector<int> ans;
        permuteAll(nums, ans, vis, output);
        return output;
    }
};