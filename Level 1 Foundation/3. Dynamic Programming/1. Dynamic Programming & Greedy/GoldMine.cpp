#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(vector<vector<int>> &mine)
{
    int n = mine.size();
    int m = mine[0].size();
    vector<vector<int>> dp(n, vector<int> (m));

    for(int c=m-1; c>=0; c--)    // going column wise
        for(int r=n-1; r>=0; r--)
        {
            if(c == m-1 && r ==n-1)     //bottom right corner
                dp[r][c] = mine[r][c];

            else if(c == m-1)    //filling right column
                dp[r][c] = mine[r][c];

            else if(r == n-1)   // filling bottom row
                dp[r][c] = max(dp[r-1][c+1], dp[r][c+1]) + mine[r][c];
            
            else if(r == 0)     // filling top row
                dp[r][c] = max(dp[r+1][c+1], dp[r][c+1]) + mine[r][c];
            
            else    // filling rest of the grid
                dp[r][c] = max({dp[r+1][c+1], dp[r][c+1], dp[r-1][c+1]}) + mine[r][c];
        }
    
    //getting max value in first column
    int MaxV = dp[0][0];            
    for(int i=1; i<n; i++)
        if(MaxV < dp[i][0])
            MaxV = dp[i][0];


    return MaxV;
        
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int>> mine(n, vector<int> (m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mine[i][j];

    cout<<solve(mine);
}