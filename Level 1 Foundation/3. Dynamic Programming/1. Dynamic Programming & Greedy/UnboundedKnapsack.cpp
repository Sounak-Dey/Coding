#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve( vector<int> &weight,  vector<int> &value, int cap)
{
    vector<int> dp(cap+1, 0);

    for(int i=0; i<weight.size(); i++)      //looping through each item
    {
        for(int j=weight[i]; j<=cap; j++)      
        {
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);     //checking whether adding the current item produces max value
        }
    }
    cout<<dp[cap];
    return 0;
}

int main()
{
    int n;
    cin>>n;

    vector<int> value(n), weight(n);
    for(int i=0; i<n; i++)
        cin>>value[i];
    for(int i=0; i<n; i++)
        cin>>weight[i];
        
    int cap;
    cin>>cap;

    solve(weight, value, cap);

    return 0;
}