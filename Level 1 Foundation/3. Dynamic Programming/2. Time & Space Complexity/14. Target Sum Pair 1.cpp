#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void targetSumPair(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());

    int l = 0;
    int r = arr.size() - 1;

    while(l < r)
    {
        int sum = arr[l] + arr[r];

        if(sum > target)
            r--;

        else if(sum < target)
            l++;

        else
        {
            cout<<arr[l]<<", "<<arr[r]<<endl;
            l++;
            r--;
        }       
    } 
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &x:arr)
        cin>>x;

    int target;
    cin>>target;

    targetSumPair(arr, target);
    return 0;
}