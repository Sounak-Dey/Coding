// 4
// ->
// 1 1 1 1
// 1 1 2
// 1 3
// 2 2
// 4


void helper(int sum, int idx, vector<int> &ans)
{
    if(sum < 0)
        return;
    
    
    ans.push_back(idx);

    if(sum == 0) //printing ans
    {
        for(auto x: ans)
            cout<<x<<" ";
        
        cout<<endl;

        return;
    }

   

    for(int i=idx; i<=sum; i++)
    {
        helper(sum - i, i, ans);
    }
}

public void printCombinations(int sum)
{
    for(int i=1; i<=sum; i++)
    {
        vector<int> ans;
        helper(sum-i, i, ans);
    }
} 

