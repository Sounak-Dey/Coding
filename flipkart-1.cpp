#include<bits/stdc++.h>
using namespace std;

 struct Edge
 {
 	int src;
 	int nbr;
 	int wt;
 };
 
 int gmin = -100;
 void findmin(priority_queue<int> pq, int k)
 {
 	
 	for(int i=0; i<k; i++)
 		pq.pop();
 	
 	int psum = 0;	
 	while(!pq.empty())
 	{
 		psum += pq.top();
 		pq.pop();
 	}
 	
 	gmin = min(gmin, psum);
 }
 
 
 
void Path(vector<vector<Edge *> > &graph, int cityA, int cityB, vector<bool> &visited, vector<int> weights, int numMagic)
 {
 	if(cityA == cityB)
 	{
 		priority_queue <int> pq;
 		
 		for(int i=0; i<weights.size(); i++)
 		{
 			pq.push(weights[i]);
 		}
 		
 		findmin(pq, numMagic);
 	}
 	
 	
 	
 	visited[cityA] = true;
 	
 	for(auto edge: graph[cityA])
 	{
 		if(visited[edge->nbr] == false)
 		{
 			weights.push_back(edge->wt);
 			Path(graph, edge->nbr, cityB, visited, weights, numMagic);
 		}
 	}
 	
 	visited[cityA] = false;
 	
 	
 	priority_queue<int> pq;
 	pq.push(-1);
 	
 	findmin(pq, numMagic);
 }

 
int shortRoute (int numCities, int cityA, int cityB, int numMagic, vector<vector<int> > cityConn)
{
    int  answer;
    // Write your code here
    
    vector<vector<Edge *> > graph(numCities);
    
    for(int i=0; i<cityConn.size(); i++)
    {
    	graph[cityConn[i][0]].push_back({cityConn[i][0], cityConn[i][1], cityConn[i][2]});
    	graph[cityConn[i][1]].push_back({cityConn[i][1], cityConn[i][0], cityConn[i][2]});
    }
    
    
    vector<bool> visited(numCities);
    vector<int> weights;
    Path(graph, cityA, cityB, visited, weights, numMagic);
    
    
    answer = gmin;
	
    
    return answer;
}

int main()
{
    //input for numCities
	int numCities;
	cin >> numCities;
	
	//input for cityA
	int cityA;
	cin >> cityA;
	
	//input for cityB
	int cityB;
	cin >> cityB;
	
	//input for numMagic
	int numMagic;
	cin >> numMagic;
	
	//input for cityConn
	int cityConn_row;
	int cityConn_col;
	cin >> cityConn_row;
	cin >> cityConn_col;
	
	vector<vector<int> > cityConn;
	for ( int idx = 0; idx < cityConn_row; idx++ )
	{
		vector<int> temp_vector;
		for ( int jdx = 0; jdx < cityConn_col; jdx++ )
		{
			int temp;
			cin >> temp;
			temp_vector.push_back(temp);
		}
		cityConn.push_back(temp_vector);
	}
	
	
    int result = shortRoute(numCities, cityA, cityB, numMagic, cityConn);
	cout << result;
	
	
    return 0;
}
