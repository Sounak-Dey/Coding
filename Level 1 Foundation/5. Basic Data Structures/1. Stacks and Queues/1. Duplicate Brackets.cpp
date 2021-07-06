#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

void solve(string &str)
{
    stack<char> st;
    bool flag = true;
    
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == ')')
        {
            if(st.top() == '(')      // duplicate bracket
            {
                cout<<"true";
                return;
            }
            else                // contains some mater inside so, not duplicate
            {
                while(st.top() != '(')
                    st.pop();
                
                st.pop();
            }
        }
        else
            st.push(str[i]);
    }
    
    cout<<"false";
}


int main()
{
    string str;
    getline(cin, str);

    solve(str);
    return 0;
}