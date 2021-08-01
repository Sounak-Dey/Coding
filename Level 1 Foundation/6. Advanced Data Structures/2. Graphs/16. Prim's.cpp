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
    int prevtx;
    int wt;
};

bool operator < (triad const &t1, const triad &t2)
{
    if(t1.wt == t2.wt)
        return t1.prevtx < t2.prevtx;
        
    return t1.wt > t2.wt;
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
    priority_queue<triad> pq;

    pq.push({0, -1, 0}); // node, previou vertex, weight of this edge

    while(!pq.empty())
    {
        int vtx = pq.top().vtx;
        int prevtx = pq.top().prevtx;
        int edgewt = pq.top().wt;
        pq.pop();// since priority queue is used ...poping must be done earlier else a minimum priority element can take over the top;

        if(visited[vtx] == false)
        {
            visited[vtx] = true;
            if(prevtx != -1)
                cout<<"["<<vtx<<"-"<<prevtx<<"@"<<edgewt<<"]"<<endl;

            for(auto edge: graph[vtx])
                if(visited[edge->nbr] == false)
                    pq.push({edge->nbr, vtx, edge->wt});
        }
    }
}