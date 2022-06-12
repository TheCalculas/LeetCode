class Solution
{
    public:
        void solveSudoku(vector<vector < char>> &board)
        {
            solve(board);
        }
    private:
    bool isValid(vector<vector < char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
        	// checking the rows:-
            if (board[i][col] == c)
                return false;
           	// checking the particular column :-
            if (board[row][i] == c)
                return false;
           	// checking the particular box :- 
            if (board[3 *(row / 3) + i / 3][3 *(col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    bool solve(vector<vector < char>> &board)
    {
       	// iterating the rows:-
        for (int i = 0; i < board.size(); i++)
        {
           	// iterating the col's :-
            for (int j = 0; j < board[0].size(); j++)
            {
               	// if the cell is not solved :-
                if (board[i][j] == '.')
                {
                   	// checking all the possiblities :-
                    for (char c = '1'; c <= '9'; c++)
                    {

                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;
                           	// recursion call further:-
                            if (solve(board))
                                return true;
                           	// backtracking :-
                            else
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }
};