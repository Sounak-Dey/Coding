 #include<bits/stdc++.h>
using namespace std;

int main()
{
    int vtces;
    cin>>vtces;
    int edges;
    cin>>edges;


    vector<vector<int>> graph(edges, (vector<int> (3)));

    for(int i=0; i<edges; i++)
    {
        cin>> graph[i][0] >> graph[i][1] >> graph[i][2];
    }

    vector<int> path(vtces+1, INT32_MAX);
    path[1] = 0;

    for(int i=0; i<(vtces-1); i++)
    {
        for(int j=0; j<edges; j++)
        {
            int u = graph[j][0];
            int v = graph[j][1];
            int wt = graph[j][2];

            if(path[u] == INT32_MAX)
                continue;
                
            path[v] = min(path[v], path[u] + wt);
        }
    }

    for(int i=2; i<=vtces; i++)
    {
        if(path[i] == INT32_MAX)
            cout<<1000000000<<" ";
        else
            cout<<path[i]<<" ";
    }

    return 0;
}