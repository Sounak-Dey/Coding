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

struct triad
{
    int vtx;
    string psf;
    int wsf;
};

bool operator < (triad const &t1, const triad &t2)
{
    if(t1.wsf == t2.wsf)
        return t1.psf.length() < t2.psf.length();
        
    return t1.wsf > t2.wsf;
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
    priority_queue<triad> pq;

    pq.push({src, to_string(src), 0}); // node, weight so far

    while(!pq.empty())
    {
        int vtx = pq.top().vtx;
        string psf = pq.top().psf;
        int wsf = pq.top().wsf;

        if(visited[vtx] == false)
        {
            visited[vtx] = true;
            cout<<vtx<<" via "<<psf<<" @ "<<wsf<<endl;

            for(auto edge: graph[vtx])
                if(visited[edge->nbr] == false)
                    pq.push({edge->nbr, psf + to_string(edge->nbr), wsf + edge->wt});
        }

        pq.pop();
    }
}