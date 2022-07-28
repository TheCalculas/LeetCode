class Solution {
public:
   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int i,j,n=intervals.size();
        vector<pair<int,int> > v;
        for(i=0;i<n;i++)
        {
            v.push_back(make_pair(intervals[i][1],intervals[i][0]));
            
        }
        sort(v.begin(),v.end());
        int en =INT_MIN,ct=0;
        for(i=0;i<n;i++)
        {
            if(en<=v[i].second )
            {
                ct++;
                en = v[i].first;
            }
        }
        return n-ct;
       
    }
};