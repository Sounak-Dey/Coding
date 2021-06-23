#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &denom, int amt)
{
    vector<int> dp(amt+1, 0);
    //dp[i] represents the number of ways in which the amount i can be achieved
    dp[0] = 1;

    for(int i=0; i<denom.size(); i++)   //denom loop runs outside to generate only combinations
    {
        int coin = denom[i];
        for(int j=coin; j<dp.size(); j++)   //counting and adding whether the
        {
            dp[j] += dp[j-coin];    // current coin produces a new combination or not
        }
    }

    return dp[amt];
}

int main()
{
    int n;
    cin>>n;
    vector<int> denom(n);
    for(int i=0; i<n; i++)
        cin>>denom[i];
    
    int amt;
    cin>>amt;
    
    cout<<solve(denom, amt);
    return 0;
}