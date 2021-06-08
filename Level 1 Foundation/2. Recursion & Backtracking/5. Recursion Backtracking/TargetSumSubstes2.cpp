#include <bits/stdc++.h>
using namespace std;

//sos - sum of set
void printTargetSumSubsets(vector<int> &a, int idx, string set, int sos, int tar)
{
    if(sos > tar)
        return;
    
    if(idx == a.size())
    {
        if(sos == tar)
            cout<<(set + ".")<<endl;
       
        return;
    }
    
    printTargetSumSubsets(a, idx+1, set + to_string(a[idx]) + ", ", sos+a[idx], tar);

    printTargetSumSubsets(a, idx+1, set, sos, tar);
}


int main()
{
    int n, tar;
    cin>>n;

    vector<int> arr(n);

    for(auto &i : arr)
        cin>>i;
    
    // for(auto i=0; i<n; i++)
    //     cin>>arr[i];

    cin>>tar;
    
    printTargetSumSubsets(arr, 0, "", 0, tar);

    return 0;
}