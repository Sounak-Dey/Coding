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

struct duo
{
    int weight;
    string path;
};

bool operator < (duo const &t1, duo const &t2)
{
    return t1.weight < t2.weight;
}

string spath;
int spathwt = INT32_MAX;
string lpath;
int lpathwt = INT32_MIN;
string cpath;
int cpathwt = INT32_MAX;
string fpath;
int fpathwt = INT32_MIN;
priority_queue<duo> pq;

void solver(vector<vector<Edge *>> &graph, int src, int dest, vector<bool> &visited, int criteria, int k, string path, int weight)
{
    if(src == dest)
    {
        if(weight < spathwt) // smallest path
        {
            spath = path;
            spathwt = weight;
        }
        if(weight > lpathwt) // largest path
        {
            lpath = path;
            lpathwt = weight;
        }
        if(weight > criteria  &&  weight < cpathwt) // ceil
        {
            cpath = path;
            cpathwt = weight;
        }
        if(weight < criteria  &&  weight > fpathwt) // floor
        {
            fpath = path;
            fpathwt = weight;
        }

        pq.push({weight, path}); // max heap
        return;
    }
        

    visited[src] = true;
    for(auto edge: graph[src])
    {
        if(visited[edge->nbr] == false)
            solver(graph, edge->nbr, dest, visited, criteria, k, path + to_string(edge->nbr), weight + edge->wt);
    }
    visited[src] = false; 
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
    int criteria;
    cin>>criteria;
    int k;
    cin>>k;

    vector<bool> visited(vtces);
    solver(graph, src, dest, visited, criteria, k, to_string(src), 0);

    for(int i=1; i<k; i++) // poping k-1 max elements to get kth largest at the top
        pq.pop();

    cout<<"Smallest Path = " << spath << "@" << spathwt<<endl;
    cout<<"Largest Path = " << lpath << "@" << lpathwt<<endl;
    cout<<"Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt<<endl;
    cout<<"Just Smaller Path than " << criteria << " = " << fpath << "@" << fpathwt<<endl;
    cout<<k << "th largest path = " << pq.top().path << "@" << pq.top().weight<<endl;

    return 0;
}