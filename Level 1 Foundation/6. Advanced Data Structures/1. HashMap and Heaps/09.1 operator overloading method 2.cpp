#include<bits/stdc++.h>
using namespace std;

struct triad
{
    int li;
    int di;
    int val;
};

bool operator < (triad const &t1, triad const &t2)
{
    return t1.val > t2.val;
}


vector<int> solve(vector<vector<int>> lists)
{
    triad t;
    vector<int> rv;
    priority_queue<triad> pq;

    int k = lists.size();

    for(int i=0; i<k; i++)
        pq.push({i, 0, lists[i][0]});

    while(!pq.empty())
    {
        rv.push_back(pq.top().val);

        t.di = pq.top().di + 1;
        t.li = pq.top().li;
        pq.pop();
        
        if(t.di < lists[t.li].size())
        {
            t.val = lists[t.li][t.di];
            pq.push(t);
        }
    }

    return rv;
}



int main()
{
    int k, n;
    cin>>k;
    vector<vector<int>> lists(k);

    for(int i=0; i<k; i++)
    {
        cin>>n;
        int x;
        for(int j=0; j<n; j++)
        {
            cin>>x;
            lists[i].push_back(x);
        }
    }

    vector<int> mlist = solve(lists);
    for(auto val: mlist)
        cout<<val<<" ";
    
    return 0;
}