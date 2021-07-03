#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(string str)
{
    int n = str.length();
    vector<int> dp(n+1);
    dp[0] = 1;
    unordered_map<char, int> prevOccur;
    for(int i=1; i<=n; i++)     // for every charachter in string
    {
        dp[i] = (2 * dp[i-1]) % 1000000007;

        if(prevOccur.find(str[i-1]) != prevOccur.end()) //if character has occured previously
        {
            dp[i] = (dp[i] - dp[prevOccur[str[i-1]] - 1]) % 1000000007;
        }   

        prevOccur[str[i-1]] = i;
    }

    dp[n]--;
    if(dp[n] < 0)
        dp[n] += 1000000007;

    return (dp[n]);
}


class Solution {
public:
    int distinctSubseqII(string s) {
        return solve(s);
    }
};