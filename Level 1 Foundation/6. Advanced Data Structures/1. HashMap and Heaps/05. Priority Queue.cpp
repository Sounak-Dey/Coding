#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {22, 99, 3, 11, 88, 4, 1};

    priority_queue<int, vector<int>, greater<int>> pq; //ascending order sytax
   // priority_queue<int> pq;  //descending order systax

    for(auto val: arr)
        pq.push(val);

    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}