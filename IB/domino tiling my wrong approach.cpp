#include<iostream>
#include<vector>

using namespace std;

int solve(int A, vector<int> dp)
{
    if(A <= 1)
        return 0;
    else if(A == 2)
        return 3;

    if(dp[A] != -1)
        return dp[A];
    
    int count;

    count = solve(A-2)*2   +  solve(A-2)*1;

    dp[A] = count;
    return count;
}

int main()
{
    int A;
    cin>>A;

    vector<int> dp(A, -1);
    cout<<solve(A);
    return 0;
}