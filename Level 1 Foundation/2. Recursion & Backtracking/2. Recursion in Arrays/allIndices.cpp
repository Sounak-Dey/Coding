#include <bits/stdc++.h>
using namespace std;

vector<int> allIndex(int arr[], int idx, int x, int n)
{
    
    if(idx==n)
    {
        vector<int> v;
        return v;
    }
    
    vector<int> v = allIndex(arr, idx+1, x, n);
    
    if(arr[idx] == x)
        v.insert(v.begin(), idx);

    return v;
}



int main()
{
    int n, x;

    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> x;

    vector<int> v = allIndex(arr, 0, x, n);

    for(auto i: v)  cout<<i<<endl;

    delete[] arr;
    return 0;
}