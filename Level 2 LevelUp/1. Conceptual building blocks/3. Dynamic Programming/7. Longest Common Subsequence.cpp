#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int solve(string &s1, string &s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    //dp[i][j] stores the LCS length till 'i'length string and 'j' length string

    for(int i = n-1; i>=0; i--)
        for(int j = m-1; j>=0; j--)
        {
            if(s1[i] == s2[j])
                dp[i][j] = dp[i+1][j+1] + 1;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
        
    return dp[0][0];
}


int main()
{
    string str1, str2;
    cin>>str1>>str2;
    cout<<solve(str1, str2);
    return 0;
}