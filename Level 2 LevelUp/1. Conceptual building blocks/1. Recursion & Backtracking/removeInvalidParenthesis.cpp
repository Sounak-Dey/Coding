#include<iostream>
#include<string>
#include<unordered_set>
#include<stack>

using namespace std;

int getMin(string str)      //using stack to get the minimum excess parenthesis
{
    stack<char> st;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '(')
            st.push(str[i]);
        else if(str[i] == ')')
        {
            if(st.size() == 0)
                st.push(str[i]);
            else if(st.top() == ')')
                st.push(str[i]);
            else if(st.top() == '(')        // pop should be at the last else if
                st.pop();                   // otherwise after poping other else if conditions might become true
        }
    }
    return st.size();
}


void solution(string str, int minRemoval, unordered_set<string> &ans)
{
    if(minRemoval == 0)
    {
        if(getMin(str) == 0)
        {
            if(ans.find(str) == ans.end())      //using set for removing duplicate answers
            {
                ans.insert(str);
                cout<<str<<endl;
            }
        }     
        return;
    }

    
    for(int i=0; i<str.length(); i++)          // removing parenthesis from every possible positon
    {
        char ch = str[i];
        str.erase(i,1);
        solution(str, minRemoval-1, ans);
        str.insert(i, 1, ch);

        //sir's method to exclude ith character
        // string left = str.substr(0, i);
        // string right = str.substr(i+1);
        // solution(left+right, minRemoval-1, ans);
    }
}



int main()
{
    string str;
    cin>>str;

    unordered_set<string> ans;
    int mr = getMin(str);

    solution(str, mr, ans);

    return 0;
}