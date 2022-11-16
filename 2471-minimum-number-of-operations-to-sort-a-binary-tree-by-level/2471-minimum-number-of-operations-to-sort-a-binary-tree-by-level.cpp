class Solution {
public:
    int findMinSwap(vector<int> &arr, int n)
    {
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i].first = arr[i];
            temp[i].second = i;
        }


        //sort the temp vector according to the values
        sort(temp.begin(), temp.end());
        
        int minimum_swaps = 0;
        int i = 0;
        while (i < n)
        {
            // If there is no need to swap then continue
            if (temp[i].second == i or temp[i].first == arr[i])
            {
                ++i;
                continue;
            }
            else
            {
                // swap the values accordingly
                swap(temp[i].first, temp[temp[i].second].first);
                swap(temp[i].second, temp[temp[i].second].second);
                
                if (temp[i].second != i)
                    i--;
            }
            
            minimum_swaps++;
            i++;
        }
        return minimum_swaps;
    }
    
    int minimumOperations(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int number = 0;
        
        while(!q.empty())
        {
            int s = q.size();
            vector<int> level;
            
            for(int i=0;i<s;i++)
            {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            number += findMinSwap(level,level.size());
        }
        return number;
    }
};