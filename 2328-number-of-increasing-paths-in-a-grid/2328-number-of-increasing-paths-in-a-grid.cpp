class Solution {
public:
      int ax[4]={1,-1,0,0};
    int ay[4]={0,0,-1,1};
     bool isvalid(int i,int j,int n,int m ){
         if(i<0||j<0||i>=n||j>=m){
            return false;
        } 
         return true;
     }
      int dp[1001][1001];
    int dfs(int i,int j,vector<vector<int>>& grid   ){
             int n=grid.size(),m=grid[0].size();
            
           if(dp[i][j]!=-1){
               
               return dp[i][j];
          }
          dp[i][j]=1;
        for(int k=0;k<4;k++){
             int x=ax[k]+i;
             int y=ay[k]+j;
             if(isvalid(x,y,n,m)&&grid[x][y]>grid[i][j] ){
                 
                  dp[i][j]=(dp[i][j]%1000000007+dfs(x,y,grid )%1000000007)%1000000007;
                 
             }
        }
        return dp[i][j]%1000000007;
         
         
    }
    int countPaths(vector<vector<int>>& grid) {
     
        int n=grid.size(),m=grid[0].size();
        int  res=0;
          
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++){
                   
            for(int j=0;j<m;j++){
            
                   dfs(i,j,grid   );
              
               
            }
        }
            for(int i=0;i<n;i++){
                   
            for(int j=0;j<m;j++){
            
                  res+=dp[i][j];
                 res=res%1000000007;
              
               
            }
        }
        return res%1000000007 ;
    }
};