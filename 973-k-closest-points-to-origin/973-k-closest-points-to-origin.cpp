class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto x: points)
        {
            pq.push({x[0]*x[0] + x[1]*x[1], x });
            if(pq.size()>k) pq.pop();
            
        }
        vector<vector<int>> vv;
        while(pq.size())
        {
            auto x = pq.top();
            vv.push_back(x.second);
            pq.pop();
        }
        
        return vv;
        
    }
};