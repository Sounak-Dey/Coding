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

        if(rel[top2][top1] == '1')  //if top2 knows top1, top2 can't be a celebrity
            st.push(top1);
        else                        // if top2 doesn't know top1, top1 can't be a celebrity
            st.push(top2);
    }

    int celeb = st.top();

    for(int i=0; i<n; i++)
    {
        if(i != celeb)
        {
            if(rel[celeb][i] == '1'  ||  rel[i][celeb] == '0')
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
        cin>>x;
        // getline(cin, x); // this is wrong, use only cin else getline will store blank in rel[0]
    
    solve(rel);
    return 0;
}