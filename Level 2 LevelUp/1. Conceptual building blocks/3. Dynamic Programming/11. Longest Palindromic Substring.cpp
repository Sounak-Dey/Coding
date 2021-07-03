#include<iostream>
#include<vector>
#include<string>
using namespace std;

int solve(string str)
{
    int n = str.length();
    vector<vector<bool>> dp(n, vector<bool> (n));
    //dp[i][j] stores true if the substring starting at i and ending at j is a palindrome
    int omax = 0;

    for(int diag=0; diag<n; diag++)
    {
        for(int i=0,j=diag; j<n; i++,j++)
        {
            if(diag==0)
                dp[i][j] = true;
            else if(diag == 1)
                dp[i][j] = (str[i] == str[j]);
            else if(str[i] == str[j])
                dp[i][j] = dp[i+1][j-1];
            
            if(dp[i][j] == true)
            omax = diag + 1;
        }
    }
    return omax;
}

int main()
{
    string str;
    cin>>str;
    
    int count = 0;

    cout<<solve(str);
    return 0;
}