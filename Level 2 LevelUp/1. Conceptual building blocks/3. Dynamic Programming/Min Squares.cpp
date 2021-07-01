#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
using namespace std;

int solve(int n)
{
    vector<int> dp(n+1);
    //dp[i] stores the min square needed to sum upto n

    dp[0] = 0;
    dp[1] = 1;
    //shortest increasing subsequence
    for(int i=2; i<=n; i++)
    {
        int minCount = INT32_MAX;
        for(int j=1; j*j<=i; j++)
        {
            if(i - j*j>=0)
                minCount = min(minCount, dp[i - j*j]);
        }
        dp[i] = minCount + 1;
    }

    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}