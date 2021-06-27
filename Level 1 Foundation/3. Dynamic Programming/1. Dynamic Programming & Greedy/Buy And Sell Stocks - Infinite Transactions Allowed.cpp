#include<iostream>
#include<vector>
#include<cstdint>

using namespace std;

//T(n) = O(n);
void solve(vector<int> &prices)
{
    int n = prices.size();
    int lsf = prices[0];    //least so far
    int profit = 0;

// we go from 0 to n maintaining the local minima and maxima
// we collect all the +ve slope profits
// as soon as their is a dip from msf we collect the profit
// and update the lsf and msf to the dipped price and start collecting the +ve slope once again
 
    for(int i=1; i<n; i++)
    {
        if(prices[i] < prices[i-1])     // when a dip comes
        {
            profit += prices[i-1] - lsf;
            lsf = prices[i];
        }
    }
    profit += prices[n-1] - lsf;    //collecting the last upstroke if exists
    cout<<profit;
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