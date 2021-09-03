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
        graph[v2].push_back(new Edge(v2, v1));
    }

    int src;
    cin>>src;

    queue<pair<int, string>> q;
    vector<bool> visited(vtces);

    q.push({src, to_string(src)});

    while(!q.empty())
    {
        if(visited[q.front().first] == false)
        {
            visited[q.front().first] = true;
            cout<<q.front().first<<"@"<<q.front().second<<endl;

            for(auto edge: graph[q.front().first])
            {
                if(visited[edge->nbr] == false)
                    q.push({edge->nbr, q.front().second + to_string(edge->nbr)});
            }
        }

        q.pop();
    }
    
    return 0;
}

