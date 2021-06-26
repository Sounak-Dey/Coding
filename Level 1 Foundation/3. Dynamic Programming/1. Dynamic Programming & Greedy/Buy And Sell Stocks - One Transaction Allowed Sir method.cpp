#include<iostream>
#include<vector>
#include<cstdint>

using namespace std;

//T(n) = O(n);
void solve(vector<int> &prices)
{
    int n = prices.size();
    int lsf = INT32_MAX;
    int maxProfit = INT32_MIN;
    int profit = INT32_MIN;

// we go from 0 to n maintaining least point so far
// and calculate the max profit that can be earned today if we sell today
// which is equal to price today - least point so far
// this removes the time required to find the least every time, thus
// reducing time complexity
 
    for(int i=0; i<n; i++)
    {
        if(prices[i]<lsf)
            lsf = prices[i];
        
        profit = prices[i] - lsf;
        if(profit > maxProfit)
            maxProfit = profit;
    }
    cout<<maxProfit;
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