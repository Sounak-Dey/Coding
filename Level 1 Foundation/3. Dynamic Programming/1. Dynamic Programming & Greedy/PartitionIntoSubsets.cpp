#include<iostream>
#include<vector>

using namespace std;

void solve(int fn, int fk)
{   
    vector<vector<long long>> dp(fn+1, vector<long long> (fk+1));
    //dp[n][k] stores the count of ways in which we can partition n items into k subsets

    for(int n=0; n<=fn; n++)
        for(int k=0; k<=fk; k++)
        {
            if(n==0 || k==0)
                dp[n][k] = 0;

            else if(n<k)
                dp[n][k] = 0;

            else if(n == k)
                dp[n][k] = 1;

            else if(n>k)
                dp[n][k] = k*dp[n-1][k] + dp[n-1][k-1];
        }

    cout<<dp[fn][fk];
}

int main()
{
    int n, k;
    cin>>n>>k;
    solve(n, k);
    return 0;
}