class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size(),ans=-1,mn=INT_MAX;
        vector<int> vis(n,-1);
        int i=node1,e=0;
        while(vis[i]==-1){
            
            vis[i]=e++;
            i=edges[i];
            if(i==-1) break;
        }
        i=node2,e=0;
        vector<int> vis1(n,-1);
        while(vis1[i]==-1){
            vis1[i]=e++;
            if(vis[i]!=-1){
                int mx=max(vis1[i],vis[i]);
                if(mx<mn){
                    ans=i;
                    mn=mx;
                }
                else if(mx==mn){
                    ans=min(i,ans);
                }
            }
            i=edges[i];
            if(i==-1) break;
        }
        
        return ans;
    }
};