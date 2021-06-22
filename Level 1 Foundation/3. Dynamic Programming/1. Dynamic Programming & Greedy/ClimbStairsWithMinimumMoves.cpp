#include <iostream>
#include<vector>

using namespace std;

//Tabulation
int cs(int arr[], int n)
{
    vector<int> minDP(n+1, INT32_MAX-1);
    minDP[n] = 0;

    for(int i=n-1; i>=0; i--)
    {
        for(int j=1; j<=arr[i]; j++)    // for size of jumps allowed from each stair
        {
            if(i+j <=n)
                if(minDP[i+j] < minDP[i])   //getting the min after all possible jumps
                {
                    minDP[i] = minDP[i + j];
                } 
        }
        minDP[i] = minDP[i] + 1;        // adding 1 for making the current jump
    }

    return minDP[0];
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0 ; i < n ;i++)
        cin>>arr[i];
        
    int minJumps = cs(arr,n);

    if(minJumps == INT32_MAX)
        cout<<"null";
    else
        cout<<minJumps;
    
    delete[] arr;
    return 0;
}