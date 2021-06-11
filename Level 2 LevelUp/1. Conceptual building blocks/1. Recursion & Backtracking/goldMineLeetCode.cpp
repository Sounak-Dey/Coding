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
    int size = bag.size();
    

        travelAndCollectGold(mine, r-1, c, visited, bag);
         if(size < bag.size())
         {
             int sum = 0;
            for(auto val: bag)      // summing the total gold collected int this path
                sum += val;
             
             if(sum > ::max)         
                    ::max = sum;
             
             int l = bag.size() - size;
             for(auto i=0; i<l; i++)
                bag.pop_back();
          }

    
  
        travelAndCollectGold(mine, r, c+1, visited, bag);
         if(size < bag.size())
         {
             int sum = 0;
            for(auto val: bag)      // summing the total gold collected int this path
                sum += val;
             
             if(sum > ::max)         
                    ::max = sum;
             
             int l = bag.size() - size;
             for(auto i=0; i<l; i++)
                bag.pop_back();
          }

    

        travelAndCollectGold(mine, r, c-1, visited, bag);
         if(size < bag.size())
         {
             int sum = 0;
            for(auto val: bag)      // summing the total gold collected int this path
                sum += val;
             
             if(sum > ::max)         
                    ::max = sum;
             
             int l = bag.size() - size;
             for(auto i=0; i<l; i++)
                bag.pop_back();
          }
    

        travelAndCollectGold(mine, r+1, c, visited, bag);
         if(size < bag.size())
         {
             int sum = 0;
            for(auto val: bag)      // summing the total gold collected int this path
                sum += val;
             
             if(sum > ::max)         
                    ::max = sum;
             
             int l = bag.size() - size;
             for(auto i=0; i<l; i++)
                bag.pop_back();
          }
    
    visited[r][c] = false;

}


// getting the max gold value amongst all connected components
void getMaxGold(vector<vector<int>> &mine)
{
    vector<vector<bool>> visited(mine.size(), vector<bool> (mine[0].size()));

    // starting from all possible boxes in the array
    for(auto i=0; i<mine.size(); i++)
        for(auto j=0; j<mine[i].size(); j++)
        {
            if(mine[i][j] != 0 )   
            {
                vector<int> bag, pval;    // for collecting the gold data of the currently chosen path
                travelAndCollectGold(mine, i, j, visited, bag);
            }   
        }
}


class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        getMaxGold(grid);
        
        return ::max;
    }
};