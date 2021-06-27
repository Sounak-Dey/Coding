#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int> &prices)
{
    //base initial state
    int pbsp = -prices[0];  //prev bought state profit
    int pssp = 0;           //prev sold state profit
    int csp = 0;
    int nbsp, nssp;

    for(int i=1; i<prices.size(); i++)
    {
        nbsp = max(pbsp, csp - prices[i]);
        nssp = max(pssp, prices[i] + pbsp);
        
        csp = pssp;
        pbsp = nbsp;
        pssp = nssp;
    }
    cout<<pssp;
}

int main()
{
    int n;
    cin>>n;
    vector<int> prices(n);
    for(auto &x: prices)
        cin>>x;

    solve(prices);
    return 0;
}