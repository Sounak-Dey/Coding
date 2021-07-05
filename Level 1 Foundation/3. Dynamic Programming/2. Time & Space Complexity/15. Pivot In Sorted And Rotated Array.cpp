#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> &arr)
{
    int l = 0;
    int r = arr.size() - 1;
    int mid = (l + r)/2;

    while(l < r)
    {
        if(arr[mid] < arr[r])
            r = mid;

        else if(arr[mid] > arr[r])
            l = mid + 1;
        else            // to handle if elements are equal
            r = mid;
        
        mid = (l+r)/2;
    }

    cout<<arr[mid];
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &i: arr)
        cin>>i;
    
    solve(arr);
    return 0;
}