#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    public:

        int src, nbr, wt;
    
        Edge(int src, int nbr, int wt)
        {
            this->src = src;
            this->nbr = nbr;
            this->wt = wt;
        }
};


bool hasPath(vector<vector<Edge *>> &graph, int src, int dest, vector<bool> &visited)
{
    if(src == dest)
        return true;


    visited[src] = true;

    for(auto edge: graph[src]) // loop through every unvisited neighbour of the current vertex
    {                         // and check whether this neighbour has a path to the destination
        if(visited[edge->nbr] == false)
        {
            if(hasPath(graph, edge->nbr, dest, visited))
                return true;    
        }
    }

    return false;
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

    if(hasPath(graph, src, dest, visited))
        cout<<"true";
    else 
        cout<<"false";


    return 0;
}