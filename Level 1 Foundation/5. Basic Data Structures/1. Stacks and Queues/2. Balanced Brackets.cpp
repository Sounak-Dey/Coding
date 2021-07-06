#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

void solve(string &str)
{
    stack<char> st;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == ')')
        {
            if(st.empty())  // to handle extra closing brackets
            {
                cout<<"false";
                return;
            }
            if(st.top() == '(')
                st.pop();
            else    // to handle bracket missmatch
            {
                cout<<"false";
                return;
            }
        }

        else if(str[i] == '}')
        {
            if(st.empty())
            {
                cout<<"false";
                return;
            }
            if(st.top() == '{')
                st.pop();
            else
            {
                cout<<"false";
                return;
            }
        }

        else if(str[i] == ']')
        {
            if(st.empty())
            {
                cout<<"false";
                return;
            }
            if(st.top() == '[')
                st.pop();
            else
            {
                cout<<"false";
                return;
            }
        }
        else if(str[i] == '('  ||  str[i] == '{'  ||  str[i] == '[')
            st.push(str[i]);
    }
    
    if(!st.empty())     // to handle extra opening brackets
        cout<<"false";
    else
        cout<<"true";
}


int main()
{
    string str;
    getline(cin, str);

    solve(str);
    return 0;
}