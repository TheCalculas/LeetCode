class Solution {
public:
    vector<vector<int>> d = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    void dfs(vector<vector<char>>& board, int r, int c, vector<vector<int>>& visited) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || visited[r][c] == 1 || board[r][c] == 'X')
            return;

        visited[r][c] = 1;
        board[r][c] = 'X';

        for (int k = 0; k < 4; k++)
            dfs(board, r + d[k][0], c + d[k][1], visited);
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;

        int cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        // Traverse the borders and mark 'O' regions and their connected neighbors as visited
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O' && visited[i][0] == 0)
                dfs(board, i, 0, visited);

            if (board[i][cols - 1] == 'O' && visited[i][cols - 1] == 0)
                dfs(board, i, cols - 1, visited);
        }

        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O' && visited[0][j] == 0)
                dfs(board, 0, j, visited);

            if (board[rows - 1][j] == 'O' && visited[rows - 1][j] == 0)
                dfs(board, rows - 1, j, visited);
        }

        // Flip the remaining 'O' cells to 'X' since they are surrounded by 'X'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        // Restore the visited 'O' cells back to 'O'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (visited[i][j] == 1)
                    board[i][j] = 'O';
            }
        }
    }
};
