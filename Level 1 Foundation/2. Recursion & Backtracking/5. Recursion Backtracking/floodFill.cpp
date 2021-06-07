#include <bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int>> maze, int sr, int sc, string psf) 
{
    if(sr<0 || sc<0 || sr == maze.size() || sc == maze[sr].size())
        return;

    if(maze[sr][sc] == 1)
        return;
    
    if((sr == maze.size()-1) && (sc == maze[sr].size()-1))
    {
        cout<<psf<<endl;
        return;
    }


    maze[sr][sc] = 1;
    
    //top
    floodfill(maze, sr-1, sc, psf + 't');

    //left
    floodfill(maze, sr, sc-1, psf + 'l');

    //down
    floodfill(maze, sr+1, sc, psf + 'd');

    //right
    floodfill(maze, sr, sc+1, psf + 'r');
}


int main() 
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int> (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    floodfill(arr, 0, 0, "");

    return 0;
}