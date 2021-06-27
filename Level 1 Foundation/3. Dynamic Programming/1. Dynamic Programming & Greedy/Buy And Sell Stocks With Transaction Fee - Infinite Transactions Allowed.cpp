/*
1. in the very first problem we have been asked to buy and sell stock but only one transition is allowed. 
    this means we got only one chance to buy the stock and hence to sell . 
    so we want to buy it on its lowest possible cost and to sell it on the day of its highest possible value. hence max profit.

2. in the previous problem we have been asked to buy and sell stock and  infinite number of transition are  allowed, 
    so instead of considering the highest and lowest possible value we must consider the small intervals of gradual growth instead of one large interval.  
    this will give us max profit .

3. now in this question , though its seems like one with the same approach as the previous one , 
    but the twist in the plot is we have to submit a fees at every sell , 
    so like in previous question we have divided the stock graph in small parts with gradual growth and add the profit we are getting from these parts, 
    but if do the same in this questions also we have to pay a fees of rupee let say 4 at every  sell , 
    if we divide the stock the graph again into those small segments (lets say we have divided into n such segments ) 
    we have to pay a fees of 4n in total so net profit =total profit -4n  which may be less then this -->(highest  possible cost of stock-lowest  possible cost of stock) or may be greater , we dont know .

so rather we have decided to check at every step the max profit .
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int> &prices, int &fee)
{
    //base initial state
    int pbsp = -prices[0];  //prev bought state profit
    int pssp = 0;           //prev sold state profit
    int nbsp, nssp;

    for(int i=1; i<prices.size(); i++)
    {
        nbsp = max(pbsp, pssp - prices[i]);
        nssp = max(pssp, prices[i] + pbsp - fee);

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
    int fee;
    cin>>fee;

    solve(prices, fee);
    return 0;
}