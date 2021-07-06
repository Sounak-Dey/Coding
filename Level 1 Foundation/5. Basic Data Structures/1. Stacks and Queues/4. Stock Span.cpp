#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void solve(vector<int> &prices)
{
    int n = prices.size();
    stack<int> stk;     
    vector<int> span(n);
    
    span[0] = 1;
    stk.push(0);    // stack stores indices of the left closest greatest value

    for(int i=1; i<n; i++)
    {
        while(!stk.empty()  &&  prices[stk.top()] <= prices[i])
            stk.pop();
        
        if(stk.empty())
            span[i] = i+1;

        else
            span[i] = i - stk.top();

        stk.push(i);
    }

    for(auto i: span)
        cout<<i<<endl;
}

int main()
{
    int n;
    cin>>n;

    vector<int> prices(n);
    for(auto &i: prices)
        cin>>i;
    
    solve(prices);
    return 0;
}