#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int solve(string &s)
{
    int n = s.length();

    vector<vector<int>> dp(n, vector<int> (n));
    //dp[i][j] stores the LPS length from 'i'char string to 'j' char string

    for(int gap=0; gap<n; gap++)
        for(int i=0,j=gap; j<n; i++,j++)
        {
            if(gap == 0)
                dp[i][j] = 1;
            else if(gap == 1)
                dp[i][j] = (s[i] == s[j]) ? 2 : 1;
            else
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        
    return dp[0][n-1];
}


int main()
{
    string str;
    cin>>str;
    cout<<solve(str);
    return 0;
}