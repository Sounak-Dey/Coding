#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n);
    //dp[i] stores the length of the longest increasing subsequence if arr[i] is included

    dp[0] = 1;

    for(int i=1; i<n; i++)
    {
        int maxLength = 0;
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j])         //checks if arr[i] can sit on top of the subsequence ending with arr[j]
                maxLength = max(maxLength, dp[j]);
        }

        dp[i] = maxLength + 1;
    }

    cout<<*max_element(dp.begin(), dp.end());
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &x:arr)
        cin>>x;
    
    solve(arr);
    return 0;
}       
