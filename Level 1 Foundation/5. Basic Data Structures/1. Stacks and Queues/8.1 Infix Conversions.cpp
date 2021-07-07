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
    stack<string> prefix;
    stack<char> opt;
    string postfix ="";
    
    for(int i=0; i<n; i++)
    {
        if(isalpha(str[i]) || isdigit(str[i]))
        {
            prefix.push(string(1, str[i]));
            postfix += str[i];
        }
        else if(str[i] == '(')
            opt.push(str[i]);
        
        else if(str[i] == ')')
        {
            while(opt.top() != '(')
            {
                string str2 = prefix.top();
                prefix.pop();
                string str1 = prefix.top();
                prefix.pop();
                char op = opt.top();
                prefix.push(op + str1 + str2);

                postfix += opt.top();

                opt.pop();
            }

            opt.pop();
        }
        else if(str[i] == '+'  ||  str[i] == '-'  ||  str[i] == '*'  ||  str[i] == '/')
        {
            while(!opt.empty()  &&  opt.top() != '('  &&  precedence(opt.top()) >= precedence(str[i]))
            {
                string str2 = prefix.top();
                prefix.pop();
                string str1 = prefix.top();
                prefix.pop();
                char op = opt.top();
                prefix.push(op + str1 + str2);

                postfix += opt.top();

                opt.pop();
            }

            opt.push(str[i]);
        }
    }

    while(!opt.empty())
    {
        string str2 = prefix.top();
        prefix.pop();
        string str1 = prefix.top();
        prefix.pop();
        char op = opt.top();
        prefix.push(op + str1 + str2);

        postfix += opt.top();

        opt.pop();
    }

    cout<<postfix;
    cout<<endl;
    cout<<prefix.top();
}


int main()
{
    string exp;
    getline(cin, exp);

    solve(exp);
    return 0;
}