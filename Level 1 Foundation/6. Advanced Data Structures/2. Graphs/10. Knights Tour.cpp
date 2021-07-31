#include<bits/stdc++.h>
using namespace std;

void solver(vector<vector<int>> &board, int r, int c, int count)
{
    if(r<0  ||  c<0  ||  r>=board.size()  ||  c>=board.size()  ||  board[r][c] != 0)
        return;


    if(count == board.size() * board.size())
    {
        board[r][c] = count;

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board.size(); j++)
                cout<<board[i][j]<<" ";
            
            cout<<endl;
        }

        cout<<endl;
    }


    board[r][c] = count;

    solver(board, r-2, c+1, count + 1);
    solver(board, r-1, c+2, count + 1);
    solver(board, r+1, c+2, count + 1);
    solver(board, r+2, c+1, count + 1);
    solver(board, r+2, c-1, count + 1);
    solver(board, r+1, c-2, count + 1);
    solver(board, r-1, c-2, count + 1);
    solver(board, r-2, c-1, count + 1);

    board[r][c] = 0;
    
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> board(n, vector<int> (n));

    int r, c;
    cin>>r>>c;

    int count = 1;
    solver(board, r, c, count);

    return 0;
}