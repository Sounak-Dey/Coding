#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>

using namespace std;

//T(n) = O(n);
void solve(vector<int> &prices)
{
    int n = prices.size();
    int lsf = prices[0];    //maintains the local minima
    int msf = prices[n-1];  //maintains the local maxima
    vector<int> dpl(n, 0), dpr(n, 0);
    int maxProfit = 0;
    //dpl[i] maintains the max profit earned if sold today or earlier
    //dpr[i] maintains the max profit earned if bought today or after
    
    
    // right to left calculating max profit so far if sold today or before
    for(int i=1; i<n; i++)
    {
        if(prices[i]<lsf)
            lsf = prices[i];
        
        dpl[i] = max(prices[i] - lsf, dpl[i-1]);
    }

    //left to right calculating the max profit so far if brought today or after
    for(int i=n-2; i>=0; i--)
    {
        if(prices[i]>msf)
            msf = prices[i];
        
        dpr[i] += max(msf - prices[i], dpr[i+1]);
    }
    
    //maxprofit earned if bought and sold earlier than today and bought and sold after today- 2 transactions
    for(int i=0; i<n; i++)
        maxProfit = max(maxProfit, dpl[i] + dpr[i]);

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