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

//time = O(V+E) * O(V + E) 
void solver(vector<vector<Edge *>> &graph, int src, vector<bool> &visited, string psf, int start)
{
    bool flag = true;
    for(auto val: visited)
    {
        if(val == false)
        {
            flag = false;
            break;
        }
    }

    if(flag == true)
    {
        for(auto edge: graph[src])
            if(edge->nbr == start)
            {
                cout<<psf<<"*"<<endl;
                return;
            }
                
        cout<<psf<<"."<<endl;
        
        return;
    }
    

    for(auto edge: graph[src])
    {
        if(!visited[edge->nbr])
        {
            visited[edge->nbr] = true;
            solver(graph, edge->nbr, visited, psf + to_string(edge->nbr), start);
            visited[edge->nbr] = false;
        }
    }
}



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

    int src;
    cin>>src;

    vector<bool> visited(vtces);
    visited[src] = true;
    solver(graph, src, visited, to_string(src), src);

    return 0;
}