#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

void solve(vector<int> &heights)
{
    int n = heights.size();
    vector<int> rb(n), lb(n);

    stack<int> stk;

    // use Next Smaller Element to Right to find right boundary
    stk.push(n-1);
    rb[n-1] = n;

    for(int i=n-2; i >= 0; i--)
    {
        while(!stk.empty()  &&  heights[stk.top()] >= heights[i])
            stk.pop();
        
        if(stk.empty())
            rb[i] = n;
        else
            rb[i] = stk.top();
        
        stk.push(i);
    }

    while(!stk.empty()) // clearing stack for reuse
        stk.pop();

    // use Next Smaller Element to Left to fing left boundary
    stk.push(0);
    lb[0] = -1;

    for(int i=1; i<n; i++)
    {
        while(!stk.empty()  &&  heights[stk.top()] >= heights[i])
            stk.pop();
        
        if(stk.empty())
            lb[i] = -1;
        else
            lb[i] = stk.top();
        
        stk.push(i);
    }


    int maxArea = 0;
    for(int i=0; i<n; i++)
    {
        int width = rb[i] - lb[i] - 1;
        int area = heights[i] * width;

        maxArea = max(area, maxArea);
    }

    cout<<maxArea;      
}

int main()
{
    int n;
    cin>>n;
    vector<int> heights(n);
    for(auto &i: heights)
        cin>>i;
    
    solve(heights);
    return 0;
}