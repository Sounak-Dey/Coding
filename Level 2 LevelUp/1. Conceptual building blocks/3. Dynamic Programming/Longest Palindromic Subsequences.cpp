#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int solve(string &s)
{
    int n = s.length();
    // string rs = s;
    // reverse(rs.begin(), rs.end());  no need just iterate through the string in reverse in line 19

    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    //dp[i][j] stores the LCS length till 'i'length string and 'j' length string

    for(int i = n-1; i>=0; i--)
        for(int j = n-1; j>=0; j--)
        {
            if(s[i] == s[(n-1)-j]) // here
                dp[i][j] = dp[i+1][j+1] + 1;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
        
    return dp[0][0];
}


int main()
{
    string str;
    cin>>str;
    cout<<solve(str);
    return 0;
}