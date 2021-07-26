#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // min heap - increasing order pop

    for(auto val: arr)
        pq.push(val);
    
    int i=0;
    while(i < arr.size())
    {
        if(i >= (arr.size()-k)) // only print the k greatest elements 
            cout<<pq.top()<<endl;
        
        pq.pop();
        i++;
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &val: arr)
        cin>>val;
    
    int k;
    cin>>k;

    solve(arr, k);
    return 0;
}