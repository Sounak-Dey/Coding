#include<bits/stdc++.h>
using namespace std;

int solver(vector<int> &oldPrices)
{
    vector<int> prices(oldPrices.size()+1, 0);
    int n = prices.size();

    for(int i=0; i<oldPrices.size(); i++)
        prices[i+1] = oldPrices[i];
    

    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = prices[1];

    for(int i=2; i<n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            dp[i] = max(dp[i], dp[i-j] + prices[j]);
        }
    }

    return dp[n-1];

}

int main()
{
    int n;
    cin>>n;

    vector<int> prices(n);
    for(auto &i: prices)
        cin>>i;
    
    cout<<solver(prices);

    return 0;
}