#include<bits/stdc++.h>
using namespace std;

int solver(vector<int> &arr) 
{
    int maxSum = arr[0], currSum = arr[0];
    vector<int> maxArr, currArr;
    currArr.push_back(arr[0]);

    for(int i=1; i<arr.size(); i++)
    {
        if(currSum >= 0)
        {
            currSum += arr[i];
            currArr.push_back(arr[i]);
        }
        else
        {
            currSum = arr[i];
            currArr.clear();
            currArr.push_back(arr[i]);
        }

        if(currSum > maxSum)
        {
            maxSum = currSum;
            maxArr = currArr;
        }
    }

    return maxSum;
}


int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &x: arr)
        cin>>x;
    
    cout<<solver(arr);

    return 0;
}