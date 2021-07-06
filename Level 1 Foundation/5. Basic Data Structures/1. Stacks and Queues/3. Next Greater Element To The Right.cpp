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
        if(arr[i] < s.top())    
        {
            ans[i] = s.top();
            s.push(arr[i]);
        }
        else
        {
            while(arr[i] >= s.top())
            {
                s.pop();   

                if(s.empty())
                    break;
                else
                    continue;
            }
            if(s.empty())
            {
                ans[i] = -1;
                s.push(arr[i]);
            }
            else
            {
                ans[i] = s.top();
                s.push(arr[i]);
            }
        }
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