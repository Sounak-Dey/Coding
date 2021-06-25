// here we calculate min and min2 for the row that we are filling parallely to reduce the time time complexity
// needed to calculate the min of the previous row when filling up a row
// this reduces removes the time for calculating min 
// so time complexity reduces from O(nkk) -> O(nk)

#include<iostream>
#include<vector>
#include<cstdint>

using namespace std;

void solve(vector<vector<int>> &colors)
{
    int n = colors.size();
    int k = colors[0].size();
    vector<vector<int>> dp(n, vector<int> (k));

    int min = INT32_MAX;
    int min2 = INT32_MAX;

    //for first row
    for(int j=0; j<k; j++)
    {
        //filling first row as same as colors
        dp[0][j] = colors[0][j];

        // calculating the min and min2 for the current row
        if(dp[0][j] < min)
        {
            min2 = min;
            min = dp[0][j];
        }
        else if(dp[0][j] < min2)
        {
            min2 = dp[0][j];
        }
    }


    for(int i=1; i<dp.size(); i++)
    {
        int nmin = INT32_MAX;
        int nmin2 = INT32_MAX;

        // for rest of the rows
        for(int j=0; j<k; j++)
        {
            //filling rest of the rows
            if(dp[i-1][j] == min)
                dp[i][j] = min2 + colors[i][j];
            else
                dp[i][j] = min + colors[i][j];


            //finding min and min2 for the current rows
            if(dp[i][j] < nmin)
            {
                nmin2 = nmin;
                nmin = dp[i][j];
            }
            else if(dp[i][j] < nmin2)
            {
                nmin2 = dp[i][j];
            }
        }

        min = nmin;
        min2 = nmin2;
    }

    cout<<min;
}


int main()
{
    int n, k;
    cin>>n>>k;

    vector<vector<int>> colors(n, vector<int> (k));
    for(int i=0; i<n; i++)
        for(int j=0; j<k; j++)
            cin>>colors[i][j];

    solve(colors);
}