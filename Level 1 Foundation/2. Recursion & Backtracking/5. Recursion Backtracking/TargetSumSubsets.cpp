#include <bits/stdc++.h>
using namespace std;

//sos - sum of set
void printTargetSumSubsets(vector<int> &a, int idx, string set, int sos, int tar)
{
   if(sos > tar)
    return;
   else if(sos == tar)
   {
       cout<<(set + ".")<<endl;
    //    return; 
   }

    for(auto i=idx; i < a.size(); i++)
    {
        printTargetSumSubsets(a, i+1, set + to_string(a[i]) + ", ", sos+a[i], tar);
    }
}


int main()
{
    int n, tar;
    cin>>n;

    vector<int> arr(n);

    // for(auto &i : arr)
    //     cin>>i;
    
    for(auto i=0; i<n; i++)
        cin>>arr[i];

    cin>>tar;
    
    printTargetSumSubsets(arr, 0, "", 0, tar);

    return 0;
}