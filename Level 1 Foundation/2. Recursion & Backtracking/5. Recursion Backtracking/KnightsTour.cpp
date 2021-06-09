#include <bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<int>> &chess)
{
    for(int i = 0; i < chess.size(); i++)
    {
        for(int j = 0; j < chess[0].size(); j++)
            cout<<(chess[i][j] + " ");

        cout<<endl;
    }
        cout<<endl;
}


void printKnightsTour(vector<vector<int>> &chess, int r, int c, int moveNum)
{
    if(r<0 || c<0 || r>=chess.size() || r>=chess[0].size() || chess[r][c]>0)
        return;

    else if(moveNum == chess.size() * chess[0].size())
    {
        chess[r][c] = moveNum;
        displayBoard(chess);
        chess[r][c] = 0;

        return;
    }


    if(chess[r][c] == 0)
    {
        chess[r][c] = moveNum;

        printKnightsTour(chess, r-2, c+1, moveNum+1);
        printKnightsTour(chess, r-1, c+2, moveNum+1);
        printKnightsTour(chess, r+1, c+2, moveNum+1);        
        printKnightsTour(chess, r+2, c+1, moveNum+1);      
        printKnightsTour(chess, r+2, c-1, moveNum+1);       
        printKnightsTour(chess, r+1, c-2, moveNum+1);       
        printKnightsTour(chess, r-1, c-2, moveNum+1);      
        printKnightsTour(chess, r-2, c-1, moveNum+1);

        chess[r][c] = 0;
    }
}



int main()
{
    int n, r, c;
    cin>> n >> r >> c;

    vector<vector<int>> chess(n, vector<int> (n, 0));

    printKnightsTour(chess, r, c, 1);

    return 0;
}