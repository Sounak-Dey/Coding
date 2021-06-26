#include<iostream>
#include<vector>
#include<cstdint>

using namespace std;

//T(n) = O(n^2);
void solve(vector<int> &prices)
{
    int n = prices.size();
    // vector<int> dp(n);
    //dp[k] stores the max profit we can earn if we buy on i'th day

    //we can optimize space by removing the dp completely and directly 
    // storing max in dpMax if current max>dpMax

    int k = 0, dpMax = INT32_MIN;
    while(k<=n)
    {
        int max = INT32_MIN;
        for(int i=k+1; i<n; i++)
        {
            if(prices[i] - prices[k]  > max)
                max = prices[i] - prices[k];
        }
        // dp[k] = max;
        // if(dp[k] > dpMax)
        //     dpMax = dp[k];
        if(max > dpMax)
            dpMax = max;
        k++;
    }
    cout<<dpMax;
}

int main()
{
    int n;
    cin>>n;
    vector<int> prices(n);
    for(auto &x: prices)
        cin>>x;

    solve(prices);
}