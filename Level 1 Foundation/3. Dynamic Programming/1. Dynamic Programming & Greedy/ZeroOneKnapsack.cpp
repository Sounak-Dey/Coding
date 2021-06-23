#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve( vector<int> &weight,  vector<int> &value, int cap)
{
    int n = value.size();
    vector<vector<int>> dp(n+1, vector<int> (cap+1, 0));
    //dp[i][j] stores the maximum value that can be obtained till weight j, using till ith item

    for(int i=1; i<=n; i++)
        for(int j=1; j<= cap; j++)
        {
            if(j - weight[i-1] >= 0)    // if can place object i
            {
                dp[i][j] = max( dp[i-1][j], dp[i-1][j-weight[i-1]] + value[i-1] );
            }
            else                        //can't place
                dp[i][j] = dp[i-1][j];
        }

        cout<<dp[n][cap];
        return 0;
}

int main()
{
    int n;
    cin>>n;

    vector<int> value(n), weight(n);
    for(int i=0; i<n; i++)
        cin>>value[i];
    for(int i=0; i<n; i++)
        cin>>weight[i];
        
    int cap;
    cin>>cap;

    solve(weight, value, cap);

    return 0;
}