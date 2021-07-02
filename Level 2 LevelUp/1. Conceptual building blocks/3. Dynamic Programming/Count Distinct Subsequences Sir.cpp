#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

long long solve(string str)
{
    int n = str.length();
    vector<long long> dp(n+1);
    dp[0] = 1;
    unordered_map<char, int> prevOccur;
    for(int i=1; i<=n; i++)     // for every charachter in string
    {
        dp[i] = 2 * dp[i-1];

        if(prevOccur.find(str[i-1]) != prevOccur.end()) //if character has occured previously
            dp[i] -= dp[prevOccur[str[i-1]] - 1];
            
        prevOccur[str[i-1]] = i;
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