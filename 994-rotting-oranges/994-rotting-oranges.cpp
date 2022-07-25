class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[0].size(); j++){
                if (grid[i][j]==2){
                    q.emplace(i,j);
                }
            }
        }
        while (!q.empty()){
            int a = q.size();
            while (a--){
                auto[r,c] = q.front(); q.pop();
                if (r>0 && grid[r-1][c]==1){
                    grid[r-1][c] = 2;
                    q.emplace(r-1,c);
                }
                if (c>0 && grid[r][c-1]==1){
                    grid[r][c-1] = 2;
                    q.emplace(r,c-1);
                }
                if (r<grid.size()-1 && grid[r+1][c]==1){
                    grid[r+1][c] = 2;
                    q.emplace(r+1,c);
                }
                if (c<grid[0].size()-1 && grid[r][c+1]==1){
                    grid[r][c+1] = 2;
                    q.emplace(r,c+1);
                }
            }
            minutes++;
        }
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[0].size(); j++){
                if (grid[i][j]==1){
                    return -1;
                }
            }
        }
        if (minutes) return minutes-1;
        return minutes;
    }
};