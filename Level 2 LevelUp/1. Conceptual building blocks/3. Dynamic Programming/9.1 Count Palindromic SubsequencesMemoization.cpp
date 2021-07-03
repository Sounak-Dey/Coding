#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int solve(string str, int i, int j,  vector<vector<int>> &dp)
{
    if(i>j)
        return 0;
        
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(i == j)
    {
        dp[i][j] = 1;
        return dp[i][j];
    }
        
    
    if(str[i] == str[j])
    {
        dp[i][j] = 1 + solve(str, i+1, j, dp) + solve(str, i, j-1, dp);
        return dp[i][j];
    }
    else
    {
        dp[i][j] = solve(str, i+1, j, dp) + solve(str, i, j-1, dp) - solve(str, i+1, j-1, dp);
        return dp[i][j];
    }
}


int main()
{
    string str;
    cin>>str;
    vector<vector<int>> dp(str.length(), vector<int> (str.length(), -1));

    cout<<solve(str, 0, str.length()-1, dp);
    return 0;
}