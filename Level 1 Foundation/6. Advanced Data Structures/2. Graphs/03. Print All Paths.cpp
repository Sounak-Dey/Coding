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


void printPath(vector<vector<Edge *>> &graph, int src, int dest, vector<bool> &visited, string path)
{
    if(src == dest)
    {
        path += to_string(dest);
        cout<<path<<endl;
        return;
    }
        

    visited[src] = true;
    for(auto edge: graph[src])
    {
        if(visited[edge->nbr] == false)
            printPath(graph, edge->nbr, dest, visited, path + to_string(src));
    }
    visited[src] = false; // bactracking to use this vertex for another path also
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
    int dest;
    cin>>dest;

    vector<bool> visited(vtces);
    printPath(graph, src, dest, visited, "");

    return 0;
}