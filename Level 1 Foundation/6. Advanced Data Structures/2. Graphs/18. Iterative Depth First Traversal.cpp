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
    int vtx;
    string psf;
};

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
    stack<duo> st;

    st.push({src, to_string(src)});

    while(!st.empty())
    {
        int vtx = st.top().vtx;
        string psf = st.top().psf;
        st.pop();

        if(visited[vtx] == false)
        {
            visited[vtx] = true;
            cout<<vtx<<"@"<<psf<<endl;

            for(auto edge: graph[vtx])
                if(visited[edge->nbr] == false)
                    st.push({edge->nbr, psf + to_string(edge->nbr)});
        }
    }

    return 0;
}