#include<iostream>
#include <vector>

using namespace std;

void coinChange(int i, vector<int> &coins, int amtsf, int tamt, string asf)
{

    if(amtsf == tamt)
    {
        cout<<asf<<"."<<endl;
        return;
    }

    if(amtsf > tamt || i == coins.size())
        return;

    //levels - denominations
    //options - yes/no
    
    //yes
    coinChange(i+1, coins, amtsf + coins[i], tamt, asf + to_string(coins[i]) + "-");

    //no
    coinChange(i+1, coins, amtsf, tamt, asf);
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