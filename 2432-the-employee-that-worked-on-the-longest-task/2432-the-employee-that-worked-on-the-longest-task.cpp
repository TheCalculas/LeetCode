class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int e = logs[0][0];
        int mn = logs[0][1];
        for(int i=1; i<logs.size(); i++)
        {
            int time = (logs[i][1] - logs[i-1][1]);
            if(logs[i][0]<e&&time==mn)
                e = logs[i][0];
            if(time>mn)
            {
              
                e = logs[i][0];
                mn = time;
            }
        }
        return e;
    }
};