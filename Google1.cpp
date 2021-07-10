#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> A{7, 3, 6, 8, 2, 1, 4, 9, 5, 10};

    vector<int> query{10, 2, 2, 5};

    vector<vector<int>> dp(A.size()+1, vector<int> (query[0]+1, 0));

    for(int i=1; i<dp.size(); i++)
    {
        for(int j=1; j<dp[0].size(); j++)
        {
            if( A[i-1]!= query[2]  &&  A[i-1]!= query[3]  &&  j - A[i-1] >= 0)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]] + 1);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[A.size()][dp[0].size()-1]<<endl;

}