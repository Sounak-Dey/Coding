#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int> >ds = {{0,1},{0,-1},{-1,0},{1,0} };

// collects max total gold value amongst all the paths generated after starting from a particular cell
int travelAndCollectGold(vector<vector<int>> &mine, int r, int c)
{
    if(mine[r][c] == 0)
        return 0;

    int gold = mine[r][c];
    int maxProfit = gold;
    mine[r][c] = 0;

    for(int i=0;i<ds.size();i++)
    {
        int newX = r + ds[i][0];
        int newY = c + ds[i][1];
        int profit = 0;

        if(newX >= 0 && newX < mine.size() && newY >=0 && newY<mine[0].size() && mine[newX][newY] != 0)
        {
            profit = travelAndCollectGold(mine, newX, newY);

            if(profit + gold > maxProfit)
                maxProfit = profit+gold;
        }
    }

    mine[r][c] = gold;

    return maxProfit;

}


class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int maxProfit=INT_MIN;

        // starting from all possible boxes in the array
        for(auto i=0; i<grid.size(); i++)
            for(auto j=0; j<grid[i].size(); j++)
                maxProfit = max(maxProfit,travelAndCollectGold(grid,i,j));

        return maxProfit;
    }
};