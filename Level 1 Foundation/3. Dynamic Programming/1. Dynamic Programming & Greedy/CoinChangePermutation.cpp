#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &denom, int amt)
{
    vector<int> dp(amt+1, 0);
    //dp[i] represents the number of ways in which the amount i can be achieved
    dp[0] = 1;

    for(int i=1; i<dp.size(); i++)      
    {
        for(int j=0; j<denom.size(); j++)   // for every amount i, we try all the 
        {                                   // denominations possible to find if it can
            if(i - denom[j] >= 0)           // produce a new permutation
                dp[i] += dp[i - denom[j]];    
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