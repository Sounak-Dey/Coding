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

void solver(vector<vector<Edge *>> &graph, vector<bool> &visited, int src, vector<int> &component)
{
    visited[src] = true;
    component.push_back(src);

    for(auto edge: graph[src])
    {
        if(!visited[edge->nbr])
            solver(graph, visited, edge->nbr, component);
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

    vector<bool> visited(vtces);
    vector<int> component;
    vector<vector<int>> cps;

    for(int v=0; v<vtces; v++)
    {
        component.clear();
        if(!visited[v])
        {
            solver(graph, visited, v, component);
            cps.push_back(component);
        }
    }

    if(cps.size() == 1)
        cout<<"true";
    else 
        cout<<"false";

    return 0;

}