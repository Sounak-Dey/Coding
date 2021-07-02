#include<iostream>
#include<vector>
using namespace std;

long long solve(string str)
{
    int n = str.length();
    vector<long long> dp(n+1);
    dp[0] = 1;

    for(int i=1; i<=n; i++)     // for every charachter in string
    {
        int prevOccur = -1;
        for(int j=i-1; j>0; j--)  // check if it has occured before
        {
            if(str[j-1] == str[i-1])
            {
                prevOccur = j;
                break;
            }    
        }

        if(prevOccur == -1)
            dp[i] = 2 * dp[i-1];
        else
            dp[i] = 2 * dp[i-1] - dp[prevOccur - 1];
        
    }
    return dp[n] - 1;
}

int main()
{
    string str;
    cin>>str;
    cout<<solve(str);
    return 0;
}