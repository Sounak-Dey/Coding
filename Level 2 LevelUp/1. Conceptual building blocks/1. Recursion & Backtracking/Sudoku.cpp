#include<vector>
#include<iostream>

using namespace std;

void display(vector<vector<int>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout<<board[i][j]<<" ";
        
        cout<<endl;
    }      
}

bool canFill(vector<vector<int>> &board, int val, int r, int c)
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


void solveSudoku(vector<vector<int>> &board, int r, int c)
{   
    if(r == 9)
    {
        display(board);
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

    if(board[r][c] == 0)
    {
        for(auto val=1; val<10; val++)
        {
            if(canFill(board, val, r, c))
            {
                board[r][c] =  val;
                solveSudoku(board, nr, nc);
                board[r][c] = 0;
            }
        }
    }
    else
        solveSudoku(board, nr, nc);   
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