#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


void solve(vector<pair<int, int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end()); // sort on the basis of start time

    stack<pair<int, int>> st, rv;

    st.push(intervals[0]); // pushing first interval

    for(int i=1; i<n; i++)
    {
        if(st.top().second >= intervals[i].first)   //if ith interval operlaps with interval at stack top 
        {
            st.top().second = max(st.top().second, intervals[i].second); // merging by pushing the larger end time
        }
        else            // if ith interval doesn't overlap .. push it as a new interval
        {
            st.push(intervals[i]);
        }
    }

    while(!st.empty())      // reversing the stack using another stack, to print in sorted manner of starting time
    {
        rv.push(st.top());
        st.pop();
    }

    while(!rv.empty())
    {
        cout<<rv.top().first<<" "<<rv.top().second<<endl;
        rv.pop();
    }
}


int main()
{
    int n;
    cin>>n;

    vector<pair<int, int>> intervals(n);

    for(auto &i: intervals)
    {
        cin>>i.first;
        cin>>i.second;
    }

    solve(intervals);
    return 0;
}