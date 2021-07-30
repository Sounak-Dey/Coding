#include<bits/stdc++.h>
using namespace std;

void solver(int srci, int srcj, vector<vector<int>> &arr, vector<vector<int>> &visited)
{
    if(srci < 0  ||  srcj < 0  ||  srci >= arr.size()  ||  srcj >= arr[srci].size()  ||  arr[srci][srcj] == 1  ||  visited[srci][srcj] == true)
        return;

    visited[srci][srcj] = true;

    solver(srci-1, srcj, arr, visited);
    solver(srci, srcj-1, arr, visited);
    solver(srci, srcj+1, arr, visited);
    solver(srci+1, srcj, arr, visited);
     
}

int main()
{
    int m, n;
    cin>>m >>n;

    vector<vector<int>> arr(m, vector<int> (n));

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    

    int component = 0;
    vector<vector<int>> visited(m, vector<int> (n));

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] == 0  &&  visited[i][j] == false)
            {
                solver(i, j, arr, visited);
                ++component;
            }
        }

    cout<<component<<endl;
    return 0;
}