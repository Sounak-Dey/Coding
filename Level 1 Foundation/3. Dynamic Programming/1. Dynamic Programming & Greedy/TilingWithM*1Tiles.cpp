#include<iostream>
#include<vector>

using namespace std;

int solve(int n, int m)
{
    vector<int> dp(n+1);
    //dp[i] represents the total number of ways we can arrange
    // the non-distinguishable tiles in the 'm * i' floor
    
    if(n >= m)    
    {
        for(int i=1; i<m; i++)  //base case
            dp[i] = 1;             // till i<m we can place only vertically
        
        dp[m] = 2;      //base case, in m*m we have 2 ways to arrange, all horizontal or all vertical

        for(int i=m+1; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-m];
        }
        cout<<dp[n];
    }
    else        //n<m we can place only vertically
        cout<<1;    
}

int main()
{
    int n, m;
    cin>>n>>m;
    solve(n, m);
    return 0;
}