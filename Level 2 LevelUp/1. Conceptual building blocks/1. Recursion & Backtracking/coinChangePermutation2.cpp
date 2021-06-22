#include<iostream>
#include <vector>

using namespace std;

void coinChange(vector<int> &coins, int amtsf, int tamt, string asf)
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

    for(int i=0; i<coins.size(); i++)
        coinChange(coins, amtsf + coins[i], tamt, asf + to_string(coins[i]) + "-");
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

    coinChange(coins, 0, amt, "");
    return 0;
}