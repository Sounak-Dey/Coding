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

void display(vector<int>& arr)
{
    cout << "[";
    for(int i=0; i < arr.size(); i++)
    {
        cout << arr[i];
        if(i < arr.size() -1) 
            cout << ", ";
    }
    
    cout << "]";
}

void displayHelper(vector<vector<int>> &arr)
{
    cout << "[";
    for(int i=0; i < arr.size(); i++)
    {
        display(arr[i]);
        if(i < arr.size() -1) 
            cout << ", ";
    }
    
    cout << "]"<<endl;
}


void cc(vector<vector<Edge *>> &graph, vector<bool> &visited, int src, vector<int> &comp)
{
    
    visited[src] = true;
    comp.push_back(src); // gather a component node by node in comp

    for(auto edge: graph[src])
    {
        if(visited[edge->nbr] == false)
            cc(graph, visited, edge->nbr, comp);
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

    vector<vector<int>> comps;
    vector<bool> visited(vtces);
    vector<int>comp;

    for(int v=0; v<vtces; v++) // start with every vertex
    {
        comp.clear();
        if(visited[v] == false) // only if visited[v] == false means that this vertex belongs to a new component
        {
            cc(graph, visited, v, comp);
            comps.push_back(comp);
        }
            
    }
    
    displayHelper(comps);
    return 0;
}