#include<iostream>
#include<vector>

using namespace std;

//Memoization - recursion
int gsp(int n, vector<int> &dp)
{
    int n1, n2, n3, totalPaths;

    if(n==0)
        return 1;
    if(n<0)
        return 0;
    
    if(dp[n]>0)
        return dp[n];

    n1 = gsp(n-1, dp);
    n2 = gsp(n-2, dp);
    n3 = gsp(n-3, dp);

    totalPaths = n1 + n2 + n3;

    return totalPaths;
}

//Tabulation - iteration
int gsp(int n)
{
    vector<int> dp(n+1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    
    return dp[n];
}

int main()
{
    int n;
    cin>>n;

    vector<int> dp(n+1);
    cout<<gsp(n, dp);
    return 0;
}