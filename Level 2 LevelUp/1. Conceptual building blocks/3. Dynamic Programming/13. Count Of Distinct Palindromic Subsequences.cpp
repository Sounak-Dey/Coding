#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

int solve(string str)
{
    int n = str.length();

    vector<vector<int>> dp(n, vector<int> (n));
    vector<int> prev(n), next(n);
    unordered_map<char, int> map;
    
    //prev[i] stores the index of previous occurance of str[i]'th character
    for(int i=0; i<n; i++)
    {
        if(map.find(str[i]) == map.end())   //if didn't occur previously
            prev[i] = -1;
        else
            prev[i] = map[str[i]];
        
        map[str[i]] = i;
    }

    map.clear();

    //next[i] stores the index of next occurance of str[i]'th character    
    for(int i=n-1; i>=0; i--)   
    {
        if(map.find(str[i]) == map.end())   //if doesn't occur anymore
            next[i] = n+1;
        else
            next[i] = map[str[i]];
        
        map[str[i]] = i;
    }

    // traversing and filling using the gap traversal
    for(int diag=0; diag<n; diag++)
    {
        for(int i=0,j=diag; j<n; i++,j++)
        {
            if(diag == 0)
                dp[i][j] = 1;

            else if(diag == 1)
                dp[i][j] = 2;

            else if(str[i] == str[j])
            {
                if(next[i] > prev[j])
                    dp[i][j] = 2*dp[i+1][j-1] +2;

                else if(next[i] == prev[j])
                    dp[i][j] = 2*dp[i+1][j-1] + 1;

                else if(next[i] < prev[j])
                    dp[i][j] = 2*dp[i+1][j-1] - dp[next[i]+1][prev[j]-1];
            }

            else if(str[i] != str[j])
            {
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            }
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