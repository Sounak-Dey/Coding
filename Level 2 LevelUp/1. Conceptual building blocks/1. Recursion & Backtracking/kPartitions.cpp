#include<iostream>
#include<vector>

using namespace std;


void solution(int p, int n, int k, int partitionCount, vector<vector<int>> &ans, int &counter)
{
    if(p > n)
    {
        if(partitionCount == k)
        {
            cout<<counter++ <<". ";
            for(auto i=0; i<ans.size(); i++)            // useless fro printing only from here
            {                                               
                cout<<"[";
                for(auto j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j];
                    if(j < ans[i].size()-1) 
                        cout << ", ";
                }
                cout<<"] ";     
            }
            cout<<endl;                                 // to here
        }
        return;
    }



    //loop through all the partition sets
    for(auto r=0; r<ans.size(); r++)
    {
        if(ans[r].size() > 0)       // placing 'p' in a non-empty partition
        {
            ans[r].push_back(p);
            solution(p+1, n, k, partitionCount, ans, counter);
            ans[r].pop_back();
        }
        else if(ans[r].size() == 0)     // placing 'p' in an empty partition
        {
            ans[r].push_back(p);       
            solution(p+1, n, k, partitionCount + 1, ans, counter);
            ans[r].pop_back();
            break;
        }  
    }
    return;
}


int main()
{
    int n, k, counter=1;
    cin>>n>>k;

    vector<vector<int>> ans(k);

    solution(1, n, k, 0, ans, counter);

    return 0;
}
