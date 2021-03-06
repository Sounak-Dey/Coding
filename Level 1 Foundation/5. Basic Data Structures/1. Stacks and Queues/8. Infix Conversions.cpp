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
    stack<string> prefix, postfix;
    stack<char> opt;

    for(int i=0; i<n; i++)
    {
        if((str[i]>='a'  && str[i]<='z')  || (str[i]>='A'  && str[i]<='Z')  ||  (str[i]>='0'  && str[i]<='9'))
        {
            prefix.push(string(1,str[i]));
            postfix.push(string(1,str[i]));
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

                str2 = postfix.top();
                postfix.pop();
                str1 = postfix.top();
                postfix.pop();
                postfix.push(str1 + str2 + op);

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

                str2 = postfix.top();
                postfix.pop();
                str1 = postfix.top();
                postfix.pop();
                postfix.push(str1 + str2 + op);


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

        str2 = postfix.top();
        postfix.pop();
        str1 = postfix.top();
        postfix.pop();
        postfix.push(str1 + str2 + op);

        opt.pop();
    }

    cout<<postfix.top();
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