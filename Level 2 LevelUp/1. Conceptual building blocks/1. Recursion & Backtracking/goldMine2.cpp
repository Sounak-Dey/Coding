#include <bits/stdc++.h>
using namespace std;

static int max = 0;


// collects total gold value in a particular connected component
void travelAndCollectGold(vector<vector<int>> &mine, int r, int c,  vector<vector<bool>> &visited, vector<int> &bag)
{
    if(r<0 || c<0 || r == mine.size() || c == mine[r].size() || mine[r][c] == 0 || visited[r][c] == true)
        return;
    

    visited[r][c] = true;
    bag.push_back(mine[r][c]);

    //north
    travelAndCollectGold(mine, r-1, c, visited, bag);

    //east
    travelAndCollectGold(mine, r, c+1, visited, bag);

    //west
    travelAndCollectGold(mine, r, c-1, visited, bag);

    //south
    travelAndCollectGold(mine, r+1, c, visited, bag);

    // here we don't make visited[r][c] = false while backtracking because we need only one path
    // a given connected component and it covers every element in that component
}


// getting the max gold value amongst all connected components
void getMaxGold(vector<vector<int>> &mine)
{
    vector<vector<bool>> visited(mine.size(), vector<bool> (mine[0].size()));

    // starting from all possible boxes in the array
    for(auto i=0; i<mine.size(); i++)
        for(auto j=0; j<mine[i].size(); j++)
        {
            if(mine[i][j] != 0 && visited[i][j] == false)   
            {
                vector<int> bag;    // for collecting the gold data of the currently chosen path
                travelAndCollectGold(mine, i, j, visited, bag);

                int sum = 0;
                for(auto val: bag)      // summing the total gold collected int this path
                    sum += val;

                if(sum > ::max)         // getting the max gold value amongst all connected components
                    ::max = sum;
            }   

        }
}



int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int>> mine(n, vector<int> (m));

    for(auto i=0; i<n; i++)
        for(auto j=0; j<m; j++)
            cin>>mine[i][j];

    getMaxGold(mine);

    cout<< ::max;

    return 0;
}