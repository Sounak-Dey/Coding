#include<vector>
#include<iostream>


using namespace std;

void fill(vector<vector<int>> &board, int r, int c, vector<bool> &cols, vector<bool> &rows, vector<bool> &grid)
{
    for(auto v=1; v<10; v++)
    {
        board[r][c] = v;

        cols[c] = true;
        rows[r] = true
    }
}


void solveSudoku(vector<vector<int>> &board, int r, int c)
{
    vector<int> cols(9), rows(9), grid(9);
    
    fill(board, r, c, cols, rows, grid);
    
}

int main()
{
    vector<vector<int>> board(9, vector<int> (9));

    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        cin>>board[i][j];

    solveSudoku(board, 0, 0);

    return 0;
}