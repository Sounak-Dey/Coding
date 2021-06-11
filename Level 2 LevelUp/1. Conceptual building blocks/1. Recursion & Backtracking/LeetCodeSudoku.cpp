#include<vector>
#include<iostream>

using namespace std;

bool canFill(vector<vector<char>> &board, char val, int r, int c)
{
    //checking in column
    for(auto col=0; col<9; col++)
        if(board[r][col] == val)
            return false;
    
    //checking in row
    for(auto row=0; row<9; row++)
        if(board[row][c] == val)
            return false;

    //calculating the index values of the mini grid within the board
    int gridi = r/3 * 3;
    int gridj = c/3 * 3;

    //cecking within the grid
    for( auto i=0; i<3; i++)
        for(auto j=0; j<3; j++)
            if(board[gridi + i][gridj + j] == val)
                return false;

    return true; 
}


void Sudoku(vector<vector<char>> &board, int r, int c,  vector<vector<char>> &sol)
{   
    if(r == 9)
    {
        sol = board;
        return;
    }       
// check for out of grid conditions

    int nr, nc;

    if(c == 8)
    {
        nr = r + 1;
        nc = 0;
    }
    else
    {
        nr = r;
        nc = c + 1;
    }

    if(board[r][c] == '.')
    {
        for(char ch='1';ch<='9';ch++)
        {
            if(canFill(board, ch, r, c))
            {
                board[r][c] = ch;
                Sudoku(board, nr, nc, sol);
                board[r][c] = '.';
            }
        }
    }
    else
        Sudoku(board, nr, nc, sol);   
}


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<char>> sol;
        
        Sudoku(board, 0, 0, sol);
        
        board = sol;
    }
};