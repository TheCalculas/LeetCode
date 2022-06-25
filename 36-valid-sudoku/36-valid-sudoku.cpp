class Solution {
public:
    bool safe(vector<vector<char>>& board,int i,int j,int n){
        int N=board.size();
        for(int k=0;k<N;k++){
            if(board[i][k]==n+'0' || board[k][j]==n+'0'){
                return false;
            }
        }
        int s=sqrt(N);
        int x=i-i%s;
        int y=j-j%s;
        for(int p=0;p<s;p++){
            for(int q=0;q<s;q++){
                if(board[x+p][y+q]==n+'0'){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int N=board.size();
        int i,j,n;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(board[i][j]!='.'){
                    n=board[i][j]-'0';
                    board[i][j]='.';
                    if(!safe(board,i,j,n)){
                        return false;
                    }
                    board[i][j]=n+'0';
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};