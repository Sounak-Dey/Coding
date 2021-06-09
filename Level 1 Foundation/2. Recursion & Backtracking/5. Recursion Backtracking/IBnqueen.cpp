bool safe(vector<string> &chess, int row, int col)
{
    // checking left diagonally up
    for(auto i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
        if(chess[i][j] == 'Q')
            return false;

    // checking straight up
    for(auto i=row-1, j=col; i>=0; i--)
        if(chess[i][j] == 'Q')
            return false;

    // checking right diagonally up
    for(auto i=row-1, j=col+1; i>=0 && j<=chess[0].size(); i--, j++)
        if(chess[i][j] == 'Q')
            return false;

    return true;        
}

void printNQueens(vector<string> &chess, int row, vector<vector<string>> &ans)
{
    if(row == chess.size())
    {
        ans.push_back(chess);
        return;
    }    


    for(auto col=0; col<chess[0].size(); col++)
    {
        if(safe(chess, row, col))
        {
            chess[row][col] = 'Q';
            printNQueens(chess, row+1, ans);
            chess[row][col] = '.';
        }
    }
}


vector<vector<string> > Solution::solveNQueens(int n) {
    
    vector<vector<string>> ans;
    vector<string> chess(n, string(n,'.'));
    
    printNQueens(chess, 0, ans);
    
    return ans;
}