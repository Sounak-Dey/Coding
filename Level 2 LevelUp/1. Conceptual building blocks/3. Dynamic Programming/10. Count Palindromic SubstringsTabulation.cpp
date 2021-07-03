#include<iostream>
#include<vector>
#include<string>
using namespace std;

int solve(string str)
{
    vector<vector<bool>> dp(str.length(), vector<bool> (str.length()));
    //dp[i][j] stores true if the substring starting at i and ending at j is a palindrome
    int count = 0;

    for(int diag=0; diag<str.length(); diag++)
    {
        for(int i=0,j=diag; j<str.length(); i++,j++)
        {
            if(diag == 0)
                dp[i][j] = true;
                
            else if(diag == 1)
                dp[i][j] = (str[i] == str[j]);
                
            else if(str[i] == str[j])
                dp[i][j] = dp[i+1][j-1];

            else
                dp[i][j] = false;
            
            if(dp[i][j] == true)
                    count++;
        }
    }
    
    return count;
}

int main()
{
    string str;
    cin>>str;
    
    int count = 0;

    cout<<solve(str);
    return 0;
}