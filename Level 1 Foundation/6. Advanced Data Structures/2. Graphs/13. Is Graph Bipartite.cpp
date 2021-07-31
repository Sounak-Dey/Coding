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


    vector<bool>visited(vtces);
    queue<pair<int, int>> q; // first -> vertex, second-> length of path till vertex
    bool flag = true;

    for(int v=0; v<vtces; v++)
    {
        if(visited[v] == false)
        {
            q.push({v, 1});

            while(!q.empty())
            {
                int vtx = q.front().first;
                int length = q.front().second;

                if(visited[vtx] == false)
                {
                    visited[vtx] = true;
                    for(auto edge: graph[vtx])
                    {
                        if(visited[edge->nbr] == false)
                            q.push({edge->nbr, length+1});
                    }
                }
                else // cycle detected
                {
                    if(length % 2 == 1) // cannot be bipartite if cycle exists and is of odd length
                        flag = false;
                }

                q.pop();
            }
        }
    }

    if(flag == true)
        cout<<"true";
    else
        cout<<"false";

    return 0;
}