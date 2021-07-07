#include<iostream>
#include<string>
#include<stack>

using namespace std;

int precedence(char op)
{
    if(op == '+'  ||  op == '-')
        return 1;
    else if(op == '*'  ||  op == '/')
        return 2;    
}


void solve(string str)
{
    int n = str.length();
    stack<string> pre, post;
    stack<char> opt;

    for(int i=0; i<n; i++)
    {
        if((str[i]>='a'  && str[i]<='z')  || (str[i]>='A'  && str[i]<='Z')  ||  (str[i]>='0'  && str[i]<='9'))
        {
            pre.push("" + str[i]);
            post.push("" + str[i]);
        }
        else if(str[i] == '(')
            opt.push(str[i]);
        
        else if(str[i] == ')')
        {
            while(opt.top() != '(')
            {
                string str2 = pre.top();
                pre.pop();
                string str1 = pre.top();
                pre.pop();
                char op = opt.top();
                pre.push(op + str1 + str2);

                str2 = post.top();
                post.pop();
                str1 = post.top();
                post.pop();
                post.push(str1 + str2 + op);

                opt.pop();
            }

            opt.pop();
        }
        else if(str[i] == '+'  ||  str[i] == '-'  ||  str[i] == '*'  ||  str[i] == '/')
        {
            while(!opt.empty()  &&  opt.top() != '('  &&  precedence(opt.top()) >= precedence(str[i]))
            {
                string str2 = pre.top();
                pre.pop();
                string str1 = pre.top();
                pre.pop();
                char op = opt.top();
                pre.push(op + str1 + str2);

                str2 = post.top();
                post.pop();
                str1 = post.top();
                post.pop();
                post.push(str1 + str2 + op);


                opt.pop();
            }

            opt.push(str[i]);
        }
    }

    while(!opt.empty())
    {
        string str2 = pre.top();
        pre.pop();
        string str1 = pre.top();
        pre.pop();
        char op = opt.top();
        pre.push(op + str1 + str2);

        str2 = post.top();
        post.pop();
        str1 = post.top();
        post.pop();
        post.push(str1 + str2 + op);

        opt.pop();
    }

    cout<<post.top();
    cout<<endl;
    cout<<pre.top();
}


int main()
{
    string exp;
    getline(cin, exp);

    solve(exp);
    return 0;
}