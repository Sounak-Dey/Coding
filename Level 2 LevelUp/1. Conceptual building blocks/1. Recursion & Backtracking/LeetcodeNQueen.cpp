#include<bits/stdc++.h>
using namespace std;

// optimized NQueen solution
void opNQueen(vector<string> &board, int r, vector<bool> &col, vector<bool> &rdiag, vector<bool> &pdiag, vector<vector<string>> &ans)
{
    if(r == board.size())
    {
        ans.push_back(board);
        return;
    }


    for(int c=0; c < board[0].size(); c++)
    {
        if(col[c]==false && rdiag[r+c]==false && pdiag[r - c + board.size()-1] == false)
        {
            board[r][c] = 'Q';

            col[c] = true;
            rdiag[r+c] = true;
            pdiag[r - c + board.size()-1] = true;

            opNQueen(board, r+1, col, rdiag, pdiag, ans);

            pdiag[r - c + board.size()-1] = false;
            rdiag[r+c] = false;
            col[c] = false;

            board[r][c] = '.';
        }
    }
}


vector<vector<string> > Solution::solveNQueens(int n) 
{

    vector<bool> col(n, false);
    vector<bool> rdiag(2*n -1, false);
    vector<bool> pdiag(2*n -1, false);

    vector<vector<string>> ans;
    vector<string> board(n, string(n,'.'));
    
    opNQueen(board, 0, col, rdiag, pdiag, ans);
    
    return ans;
}