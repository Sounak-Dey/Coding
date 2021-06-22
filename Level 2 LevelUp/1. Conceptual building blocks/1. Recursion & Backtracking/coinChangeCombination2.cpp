#include<iostream>
#include <vector>

using namespace std;

void coinChange(int idx, vector<int> &coins, int amtsf, int tamt, string asf)
{

    if(amtsf == tamt)
    {
        cout<<asf<<"."<<endl;
        return;
    }

    if(amtsf > tamt)
        return;

    //levels - spots
    //options - denominations
    //repitions of coins allowed

    for(int i=idx; i<coins.size(); i++)
        coinChange(i, coins, amtsf + coins[i], tamt, asf + to_string(coins[i]) + "-");
}

int main()
{
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int &i: coins)
        cin>>i;
    
    int amt;
    cin>>amt;

    coinChange(0, coins, 0, amt, "");
    return 0;
}