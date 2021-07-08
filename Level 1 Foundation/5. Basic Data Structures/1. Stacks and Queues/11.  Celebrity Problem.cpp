#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;


void solve(vector<string> &rel)
{
    int n = rel.size();

    stack<int> st;

    for(int i=0; i<n; i++)
        st.push(i);
    
    while(st.size() > 1)
    {
        int top1 = st.top();
        st.pop();
        int top2 = st.top();
        st.pop();

        if(rel[top2][top1] == '1')  //if top1 knows top2, top1 can't be a celebrity
            st.push(top1);
        else                        // if top1 doesn't know top2, top2 can't be a celebrity
            st.push(top2);
    }

    int celeb = st.top();

    for(int i=0; i<n; i++)
    {
        if(i != celeb)
        {
            if(rel[celeb][i] == 1  ||  rel[i][celeb] == 1)
            {
                cout<<"none";
                return;
            }
        }
    }

    cout<<celeb;
}


int main()
{
    int n; 
    cin>>n;

    vector<string> rel(n);
    for(auto &x: rel)
        getline(cin, x);
    
    solve(rel);
    return 0;
}