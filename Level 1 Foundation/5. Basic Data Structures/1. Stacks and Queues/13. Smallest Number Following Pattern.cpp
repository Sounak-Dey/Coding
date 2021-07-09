#include<iostream>
#include<string>
#include<stack>

using namespace std;


void solve(string str)
{
    int n = str.length();
    stack<char> st;
    string ans = "";

    if(str[0] == 'd')
        st.push('1');
    else
        ans.push_back('1');

    for(int i=2; i<=n+1; i++)
    {
        if(str[i-2] == 'd')
        {
            st.push('0' + i);
        }
        else if(str[i-2] == 'i')
        {
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }

            st.push('0'+ i);
        }
    }

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    cout<<ans;
}


int main()
{
    string str;
    cin>>str;

    solve(str);
    return 0;
}