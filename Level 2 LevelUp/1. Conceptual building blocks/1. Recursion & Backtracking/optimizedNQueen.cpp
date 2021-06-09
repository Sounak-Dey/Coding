#include <bits/stdc++.h>
using namespace std;

// optimized NQueen solution
void opNQueen(vector<vector<bool>> &board, int r, vector<bool> &col, vector<bool> &rdiag, vector<bool> &pdiag, string asf)
{
    if(r == board.size())
    {
        cout<<asf + "."<<endl;
        return;
    }


    for(int c=0; c < board[0].size(); c++)
    {
        if(col[c]==false && rdiag[r+c]==false && pdiag[r - c + board.size()-1] == false)
        {
            board[r][c] = true;

            col[c] = true;
            rdiag[r+c] = true;
            pdiag[r - c + board.size()-1] = true;

            opNQueen(board, r+1, col, rdiag, pdiag, asf + to_string(r) + "-" + to_string(c) +"' ");

            pdiag[r - c + board.size()-1] = false;
            rdiag[r+c] = false;
            col[c] = false;

            board[r][c] = false;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<vector<bool>> board(n, vector<bool> (n, false));
    vector<bool> col(n, false);
    vector<bool> rdiag(2*n -1, false);
    vector<bool> pdiag(2*n -1, false);

    opNQueen(board, 0, col, rdiag, pdiag, "");

    return 0;
}