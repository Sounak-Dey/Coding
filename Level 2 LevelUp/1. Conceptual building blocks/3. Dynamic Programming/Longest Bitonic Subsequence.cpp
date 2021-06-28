#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dplis(n), dplds(n);
    //dplis[i] stores the length of the longest increasing subsequence ending with arr[i] 
    //dplds[i] stores the length of the longest decreasing subsequence starting from arr[i]
    dplis[0] = 1;
    dplds[n-1] = 1;

    //LIS
    for(int i=1; i<n; i++)
    {
        int maxLength = 0;
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j])         //checks if arr[i] can sit on top of the subsequence ending with arr[j]
                maxLength = max(maxLength, dplis[j]);
        }

        dplis[i] = maxLength+1;
    }

    //LDS
    for(int i=n-2; i>=0; i--)
    {
        int maxLength = 0;
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])         //checks if arr[i] can sit on top of the subsequence starting with arr[j]
                maxLength = max(maxLength, dplds[j]);
        }

        dplds[i] = maxLength+1;
    }

    int omax=0, bitonicScore;
    for(int i=0; i<n; i++)
    {
        if(dplis[i]>1 && dplds[i]>1)    // else doesn't form a mountain
        {
            bitonicScore = dplis[i] + dplds[i] - 1;
            omax = max(omax, bitonicScore);
        }
    }
        

    if(omax == 1)
        return 0;
    else
        return omax;
} 


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &x:arr)
        cin>>x;
    
    if(arr.size()<3)
        cout<<0;
    else
        cout<<solve(arr);
        
        
    return 0;
}       
