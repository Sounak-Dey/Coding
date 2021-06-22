#include <iostream>
#include<vector>

using namespace std;

//Tabulation
int cs(int arr[], int n)
{
    vector<int> dp(n+1, 0);
    dp[n] = 1;

    for(int i=n-1; i>=0; i--)
    {
        for(int j=1; j<=arr[i]; j++)    // for number of jumps allowed from each stair
        {
            if(i+j <=n)
                dp[i] += dp[i + j];
        }
    }

    return dp[0];
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0 ; i < n ;i++)
        cin>>arr[i];
        
    cout<<cs(arr,n)<<endl;
    
    delete[] arr;
    return 0;
}