#define M 1000000007
int Solution::solve(int n) {
    
    
    vector<vector<long long int>> dp(n+1,vector<long long int>(8,0));
    dp[0][7]=1;
    
    for(int i=1;i<=n;i++){
        
        dp[i][1]=(dp[i][1]+dp[i-1][6])%M;
        dp[i][2]= (dp[i][2]+dp[i-1][5])%M;
        dp[i][3]= (dp[i][3]+dp[i-1][4]+dp[i-1][7])%M;
        
        dp[i][4]= (dp[i][4]+dp[i-1][3])%M;
        dp[i][5]=( dp[i][5]+dp[i-1][2])%M;
        
        dp[i][6]= (dp[i][6]+dp[i-1][7]+dp[i-1][1])%M;
        dp[i][7]= ( dp[i][7]+dp[i-1][6]+dp[i-1][3]+dp[i-1][0])%M;
        
        dp[i][0]=dp[i-1][7];
    }
    
    return dp[n][7];
}