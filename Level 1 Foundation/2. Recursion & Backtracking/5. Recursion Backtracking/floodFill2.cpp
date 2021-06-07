#include <bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int>> maze, int sr, int sc, string psf, vector<vector<bool>> visited) 
{

    if(sr<0 || sc<0 || sr == maze.size() || sc == maze[sr].size() || maze[sr][sc] == 1 || visited[sr][sc] == true)
        return;
    
    if((sr == maze.size()-1) && (sc == maze[sr].size()-1))
    {
        cout<<psf<<endl;
        return;
    }


    visited[sr][sc] = true;

    //top
    floodfill(maze, sr-1, sc, psf + 't', visited);

    //left
    floodfill(maze, sr, sc-1, psf + 'l', visited);

    //down
    floodfill(maze, sr+1, sc, psf + 'd', visited);

    //right
    floodfill(maze, sr, sc+1, psf + 'r', visited);
}


int main() 
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int> (m));
    vector<vector<bool>> v(n, vector<bool> (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];   
            v[i][j] == false;
        }

            
    floodfill(arr, 0, 0, "", v);

    return 0;
}