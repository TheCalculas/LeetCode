class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        
        int n = ast.size();
        vector<int> stck;
        
        for(int i = 0; i<n;)
        {
            if(stck.empty() || ast[i]>0 || stck.back()<0)
            {
                stck.push_back(ast[i]);
                i++;continue;
            }
            else
            {
                if(stck.back()+ast[i]>0) i++;
                else if(stck.back()+ast[i]<0) stck.pop_back();
                else {stck.pop_back();i++;}
                    
            }
        }
        return stck;
    }
};