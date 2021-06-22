#include<iostream>
#include <vector>

using namespace std;

void coinChange(vector<int> &coins, vector<bool> &used, int amtsf, int tamt, string asf)
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
        if(used[i] == false)
        {
            used[i] = true;
            coinChange(coins, used, amtsf + coins[i], tamt, asf + to_string(coins[i]) + "-");
            used[i] = false;
        }
        
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

    vector<bool> used(n, false);
    coinChange(coins, used, 0, amt, "");
    return 0;
}