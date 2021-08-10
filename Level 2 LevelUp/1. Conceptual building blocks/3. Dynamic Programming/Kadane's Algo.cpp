#include<bits/stdc++.h>
using namespace std;

// doesn't work if all the elements are negative
int solver(vector<int> &arr) 
{
    int maxSum = arr[0], currSum = arr[0];
    vector<int> maxArr, currArr;
    currArr.push_back(arr[0]);

    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i] < 0)
        {
            currArr.push_back(arr[i]);
            currSum += arr[i];
        }
        else
        {
            if(arr[i] + currSum  >  arr[i])
            {
                currArr.push_back(arr[i]);
                currSum += arr[i];
            }
            else
            {
                currArr.clear();
                currArr.push_back(arr[i]);
                currSum = arr[i];
            }

            if(currSum > maxSum)
            {
                maxSum = currSum;
                maxArr = currArr;
            }
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