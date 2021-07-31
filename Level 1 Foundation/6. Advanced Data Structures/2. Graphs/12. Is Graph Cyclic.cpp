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


// using BFS
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

    queue<int> q;
    vector<bool> visited(vtces);
    bool flag = false;

    for(int v=0; v<vtces; v++)
    {
        if(visited[v] == false)
        {
            q.push(v);

            while(!q.empty())
            {
                if(visited[q.front()] == false)
                {
                    visited[q.front()] = true;

                    for(auto edge: graph[q.front()])
                    {
                        if(visited[edge->nbr] == false)
                            q.push(edge->nbr);
                            
                        // else if(visited[edge->nbr] == true)
                        //     flag = true;
                    }
                }
                else
                {
                    flag = true;
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