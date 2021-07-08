#include<iostream>
#include<string>
#include<stack>

using namespace std;

int operate(int v1, int v2, char op)
{
    if(op == '+')
        return v1 + v2;

    else if(op == '-')
        return v1 - v2;

    else if(op == '*')
        return v1 * v2;

    else if(op == '/')
        return v1 / v2;
    
    else 
        return 0;
}


void solve(string exp)
{
    int n = exp.size();

    stack<int> eval;
    stack<string> infix, prefix;

    for(int i=0; i<n; i++)
    {
        if(isdigit(exp[i]))
        {
            eval.push(exp[i] - '0');
            infix.push(string(1, exp[i]));
            prefix.push(string(1, exp[i]));
        }

        else if(exp[i] == '+'  ||  exp[i] == '-'  ||  exp[i] == '*'  ||  exp[i] == '/' )
        {
            char op = exp[i];

            int v2 = eval.top();
            eval.pop();
            int v1 = eval.top();
            eval.pop();
            eval.push(operate(v1, v2, op));

            string s2 = infix.top();
            infix.pop();
            string s1 = infix.top();
            infix.pop();
            infix.push("(" + s1 + op + s2 + ")");

            s2 = prefix.top();
            prefix.pop();
            s1 = prefix.top();
            prefix.pop();
            prefix.push(op + s1 + s2);
        }    
    }

    cout<<eval.top()<<endl;
    cout<<infix.top()<<endl;
    cout<<prefix.top()<<endl;
}


int main()
{
    string exp;
    getline(cin, exp);

    solve(exp);
    return 0;
}