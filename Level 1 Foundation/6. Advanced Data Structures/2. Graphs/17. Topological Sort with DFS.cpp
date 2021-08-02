#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, nbr;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
    }
};


void topoSort(vector<vector<Edge *>> &graph, int v, vector<bool> &visited, stack<int> &st)
{
    visited[v] = true;

    for(auto edge: graph[v])
    {
        if(visited[edge->nbr] == false)
            topoSort(graph, edge->nbr, visited, st);
    }

    st.push(v);
}



int main()
{
    int vtces;
    cin>>vtces;
    vector<vector<Edge *>> graph(vtces);

    int edges;
    cin>>edges;

    int v1, v2;
    for(int i=0; i<edges; i++) 
    {
        cin>>v1>>v2;
        graph[v1].push_back(new Edge(v1, v2));
    }



    vector<bool> visited(vtces);
    stack<int> st;

    for(int v=0; v<vtces; v++)
    {
        if(visited[v] == false)
            topoSort(graph, v, visited, st);
    }

    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}