#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> solve(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;

    // for last element
    s.push(arr[n-1]);
    ans[n-1] = -1;


    for(int i=n-2; i>=0; i--)
    {
        while(s.size() > 0  &&  arr[i] >= s.top()) //pop till we find an element larger than the current element 'arr[i]' 
            s.pop();

        if(s.empty())   // if no next larger element to the right found
            ans[i] = -1;
        else                // if found
            ans[i] = s.top();

        s.push(arr[i]);     // push the current element so it can become next larger element to the right for some other element
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n), ans(n);
    for(auto &x: arr)
        cin>>x;
    
    ans = solve(arr);
    
    for(auto x: ans)
        cout<<x<<endl;
    
    return 0;
}