#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, nbr, wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};


int main()
{
    int vtces;
    cin>>vtces;
    vector<vector<Edge *>> graph(vtces);

    int edges;
    cin>>edges;

    int v1, v2, wt;
    for(int i=0; i<edges; i++) 
    {
        cin>>v1>>v2>>wt;
        
        graph[v1].push_back(new Edge(v1, v2, wt));
        graph[v2].push_back(new Edge(v2, v1, wt));
    }

    int src, t;
    cin>>src>>t;

    vector<bool>visited(vtces);
    queue<pair<int, int>> q;

    q.push({src, 1});
    int count = 0;

    while(!q.empty())
    {
        int vtx = q.front().first;
        int time = q.front().second;

        if(visited[vtx] == false)
        {
            visited[vtx] = true;

            if(time > t)
                break;

            count++;

            for(auto edge: graph[vtx])
            {
                if(visited[edge->nbr] == false)
                    q.push({edge->nbr, time+1});               
            }
        }

        q.pop();
    }


    cout<<count<<endl;

    return 0;
}