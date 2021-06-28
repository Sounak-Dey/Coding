#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>

using namespace std;

//T(n) = O(nnk);
int solve(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<int>> dp(k+1, vector<int> (n,0));
    //dp[t][day] denotes the max profit that can be earned if t transactions are done till day'th day

    for(int t=1; t<=k; t++)
    {
        for(int day=1; day<n; day++)
        {
            dp[t][day] = dp[t][day-1];
            
            for(int pday=0; pday<day; pday++)
            {
                int prof = dp[t-1][pday] + prices[day]-prices[pday];

                dp[t][day] = max(dp[t][day], prof);
            }
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

    cout<<solve(prices, k);
}