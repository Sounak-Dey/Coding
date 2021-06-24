#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 2147483647

using namespace std;

int solve( vector<int> &coins, int amount)
{
	vector<int> dp(amount+1, INT_MAX-1);
	//dp[i] stores the minimum number of coins needed to reach amount i
	dp[0] = 0;

	for(int i=0; i<coins.size(); i++)      //looping through each coin
	{
		for(int j=coins[i]; j<dp.size(); j++)      
		{
			dp[j] = min(dp[j], dp[j-coins[i]] + 1);     //checking whether adding the current coin produces min coins
		}
	}

	if(dp[amount] == INT_MAX-1)
		return -1;
	else
		return dp[amount];
}


class Solution 
{
    public:
        int coinChange(vector<int>& coins, int amount) 
        {
            return solve(coins, amount);
        }
};