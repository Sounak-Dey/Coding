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



int main()
{
    int vtces;
    cin>>vtces;
    vector<vector<Edge *>> graph(vtces); // adjacency list i.e vector of vector of edges

    int edges;
    cin>>edges;

    int v1, v2, wt;
    for(int i=0; i<edges; i++)
    {
        cin>>v1>>v2>>wt;
        
        graph[v1].push_back(new Edge(v1, v2, wt)); // append new edge at the end of list of edges from a vertex
        graph[v2].push_back(new Edge(v2, v1, wt));
    }

    // display adjacency list
    for(auto x: graph)
    {
        for(auto e: x)
            cout<<e->src<<" "<<e->nbr<<" "<<e->wt<<"\t";
        
        cout<<endl;
    }

    return 0;
}