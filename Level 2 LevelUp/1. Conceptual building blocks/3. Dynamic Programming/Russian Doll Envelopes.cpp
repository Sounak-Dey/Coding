#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<pair<int, int>> &dim)
{
    int n = dim.size();

    //sort on the basis of first elements(width)
    sort(dim.begin(), dim.end());

    vector<int> dp(n);  
    //dp[i] stores the maxCount of number of envelops that can nested if ith envelop is included
    int maxCount;

    //LIS on length
    for(int i=0; i<n; i++)
    {
        maxCount = 0;
        for(int j=0; j<i; j++)
        {
            if(dim[j].second < dim[i].second)
                maxCount = max(maxCount, dp[j]);
            
        }
        dp[i] = maxCount + 1;
    }

    return *max_element(dp.begin(), dp.end());

}

int main()
{
    int n;
    cin>>n;

    vector<pair<int, int>> dim(n);
    for(int i=0; i<n; i++)
        cin>>dim[i].first>>dim[i].second;
    
    cout<<solve(dim);
    return 0;
}