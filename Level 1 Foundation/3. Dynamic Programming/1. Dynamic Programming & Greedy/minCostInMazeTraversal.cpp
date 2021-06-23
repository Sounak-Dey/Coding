#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Tabulation
int soltuion(vector<vector<int>> &maze)
{
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>> dp(n, vector<int> (m));

    dp[n-1][m-1] = maze[n-1][m-1];

    for(int i=n-1; i>=0; i--)
        for(int j=m-1; j>=0; j--)
        {
            if(i < n-1 && j < m-1)                      // filling rest of the minCost DP
                dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + maze[i][j];

            else if(i == n-1 && j!=m-1)                 // filling last row
                dp[i][j] = dp[i][j+1] + maze[i][j];

            else if(i != n-1 && j==m-1)                // filling last column
                dp[i][j] = dp[i+1][j] + maze[i][j];
        }

    return dp[0][0];
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int>> maze(n, vector<int> (m));
    for(auto i=0; i<n; i++)
        for(auto j=0; j<m; j++)
            cin>>maze[i][j];
        
    
    cout<<soltuion(maze);

    return 0;

}