#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool bridgeSort(pair<int, int> &a, pair<int, int> &b)
{
    if(a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int solve(vector<pair<int, int>> &bridges)
{
    int n = bridges.size();
    sort(bridges.begin(), bridges.end(), bridgeSort);

    vector<int> dp(n);
    //dp[i] stores the count of bridges(based on LIS on south) including ith bridge

    //LIS on basis of south
    for(int i=0; i<n; i++)
    {
        int maxCount = 0;
        for(int j=0; j<i; j++)
        {
            if(bridges[i].second > bridges[j].second)
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

    vector<pair<int, int>> bridges(n);
    for(int i=0; i<n; i++)
        cin>>bridges[i].first>>bridges[i].second;

    cout<<solve(bridges);
}