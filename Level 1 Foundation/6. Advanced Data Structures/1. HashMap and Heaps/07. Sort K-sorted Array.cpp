#include<bits/stdc++.h>
using namespace std;

// this is better than simply sorting the array using sort(), because its complexity will be O(nlogn), here we solve it in O(nlogk)
void solve(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<=k; i++) // collect k+1 elements in the pq at first
        pq.push(arr[i]);
    
    int i=k+1;
    while(i < arr.size()) // fro the remaining elements, pop top and push 1
    {
        arr[i-k-1] = pq.top(); // the top of pq is the minimum element, place it in the correct spot
        pq.pop();
        pq.push(arr[i]);
        i++;
    }

    while(!pq.empty()) // fill the reamaining elements in heap into the arr
    {
        arr[i-k-1] = pq.top();
        pq.pop();
        i++;
    }

    for(auto val: arr)
        cout<<val<<endl;
}


int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &val: arr)
        cin>> val;
    
    int k;
    cin>>k;

    solve(arr, k);
    return 0;
}