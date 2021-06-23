#include<iostream>
#include<vector>

using namespace std;

//Tabulation
void solve(vector<int> &arr, int tar)
{
    int n = arr.size();

    vector<vector<bool>> dp(n+1, vector<bool> (tar+1, false));

    for(int i=0; i<=n; i++)
        for(int j=0; j<=tar; j++)
        {
            if(j == 0)  // leftmost column
                dp[i][j] = true;
            else if(i == 0)  //top row
                dp[i][j] = false;
            else if(dp[i-1][j] == true)     //don't include arr[i-1]
                dp[i][j] = true;    
            else if(j-arr[i-1] >= 0  &&  (dp[i-1][j-arr[i-1]] == true))     // include arr[i-1]
                dp[i][j] = true;
        }

        if(dp[n][tar] == true)
            cout<<"true";
        else
            cout<<"false";
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int tar;
    cin>>tar;

    solve(arr, tar);
    return 0;
}