// solved by converting the clubs into a component 
// theirfore different clubs are the differnt components of the graph
// ans is the sum of products of different component sizes 2 chosen a a time

#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int vertex;
    int nbr;

    Edge(int vertex, int nbr)
    {
        this->vertex = vertex;
        this->nbr = nbr;
    }
};


void solver(vector<vector<Edge *>> &graph, int src, vector<bool> &visited, vector<int> &component)
{

    visited[src] = true;
    component.push_back(src);

    for(auto edge: graph[src])
    {
        if(!visited[edge->nbr])
            solver(graph, edge->nbr, visited, component);
    }
}

int main()
{
    int n, k;
    cin>>n>>k;
    vector<vector<Edge *>> graph(n);

    int v1, v2;
    for(int i=0; i<k; i++) 
    {
        cin>>v1>>v2;
        
        graph[v1].push_back(new Edge(v1, v2));
        graph[v2].push_back(new Edge(v2, v1));
    }

    vector<vector<int>> cps;
    vector<int> component;
    vector<bool> visited(n);

    for(int v=0; v<n; v++)
    {
        component.clear();
        if(!visited[v])
        {
            solver(graph, v, visited, component);
            cps.push_back(component);
        }
    }


    int ans = 0;
    for(int i=0; i<cps.size(); ++i)
        for(int j=i+1; j<cps.size(); ++j)
            ans += cps[i].size() * cps[j].size();

    cout<<ans;


    return 0;

}