#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>

using namespace std;

//T(n) = O(n^2);
int solve(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<int>> dp(k+1, vector<int> (n,0));
    //dp[t][day] denotes the max profit that can be earned if t transactions are done till day'th day

    for(int t=1; t<=k; t++)
    {
        int m = INT32_MIN;
        for(int day=1; day<n; day++)
        {
            //m keeps track of the max money left if (t-1) transactions were completed and a share was brought(on the same day) on any of the previous days
            m = max(m, dp[t-1][day-1] - prices[day-1]);
              
            dp[t][day] = max(dp[t][day-1], m + prices[day]);
        }
    }

    return dp[k][n-1];
}


int main()
{
    int n;
    cin>>n;
    vector<int> prices(n);
    for(auto &x: prices)
        cin>>x;
    int k;
    cin>>k;

    if(prices.size() == 0)
        cout<<0;
    else
        cout<<solve(prices, k);
}