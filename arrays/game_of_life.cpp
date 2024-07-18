class Solution
{
public:
    int delrow[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int delcol[8] = {1, 0, -1, 0, -1, 1, 1, -1};

    int countNeighbours(vector<vector<int>> &board, int row, int col, int m, int n)
    {
        int count = 0;
        for (int i = 0; i < 8; i++)
        {
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 1)
            {
                count++;
            }
        }
        return count;
    }

    void game(vector<vector<int>> &board, int i, int j, int m, int n)
    {
        if (j == n)
        {
            i++;
            j = 0;
            if (i == m)
            {
                return;
            }
        }
        int number = countNeighbours(board, i, j, m, n);
        game(board, i, j + 1, m, n);
        if (number > 3 || number < 2)
        {
            board[i][j] = 0;
        }
        else if (number == 3)
        {
            board[i][j] = 1;
        }
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        game(board, 0, 0, m, n);
    }
};

//-----------------------------------------------
// bit manipulation technique;
// void gameOfLife(vector<vector<int>>& board) {
//     int m = board.size(), n = m ? board[0].size() : 0;
//     for (int i=0; i<m; ++i) {
//         for (int j=0; j<n; ++j) {
//             int count = 0;
//             for (int I=max(i-1, 0); I<min(i+2, m); ++I)
//                 for (int J=max(j-1, 0); J<min(j+2, n); ++J)
//                     count += board[I][J] & 1;
//             if (count == 3 || count - board[i][j] == 3)
//                 board[i][j] |= 2;
//         }
//     }
//     for (int i=0; i<m; ++i)
//         for (int j=0; j<n; ++j)
//             board[i][j] >>= 1;
// }