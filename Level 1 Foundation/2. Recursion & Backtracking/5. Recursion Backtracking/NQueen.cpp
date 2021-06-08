#include <bits/stdc++.h>
using namespace std;

bool safe(vector<vector<int>> &chess, int row, int col)
{
    // checking left diagonally up
    for(auto i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
        if(chess[i][j] == 1)
            return false;

    // checking straight up
    for(auto i=row-1, j=col; i>=0; i--)
        if(chess[i][j] == 1)
            return false;

    // checking right diagonally up
    for(auto i=row-1, j=col+1; i>=0 && j<=chess[0].size(); i--, j++)
        if(chess[i][j] == 1)
            return false;

    return true;        
}


void printNQueens(vector<vector<int>> &chess, string qsf, int row)
{
    // checking for row == chess.size() is enough and counting the number of queens placed is 
    // not neccessary because if a queen cannot be placed in a row then we backtrack
    // and if we reach row = chess.size() that means we have placed n queens.

    if(row == chess.size())
    {
        cout<<(qsf + ".")<<endl;
        return;
    }


    for(auto col=0; col<chess[0].size(); col++)
    {
        if(safe(chess, row, col))
        {
            chess[row][col] = 1;
            printNQueens(chess, qsf + to_string(row) + "-" + to_string(col) + ", ", row+1);
            chess[row][col] = 0;
        }
    }
}



int main()
{
    int n;
    cin>> n;

    vector<vector<int>> chess(n, vector<int> (n, 0));

    printNQueens(chess, "", 0);

    return 0;
}