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
    stack<string> infix, posfix;

    for(int i=n-1; i>=0; i--)
    {
        if(isdigit(exp[i]))
        {
            eval.push(exp[i] - '0');
            infix.push(string(1, exp[i]));
            posfix.push(string(1, exp[i]));
        }

        else if(exp[i] == '+'  ||  exp[i] == '-'  ||  exp[i] == '*'  ||  exp[i] == '/' )
        {
            char op = exp[i];

            int v1 = eval.top();
            eval.pop();
            int v2 = eval.top();
            eval.pop();
            eval.push(operate(v1, v2, op));

            string s1 = infix.top();
            infix.pop();
            string s2 = infix.top();
            infix.pop();
            infix.push("(" + s1 + op + s2 + ")");

            s1 = posfix.top();
            posfix.pop();
            s2 = posfix.top();
            posfix.pop();
            posfix.push(s1 + s2 + op);
        }    
    }

    cout<<eval.top()<<endl;
    cout<<infix.top()<<endl;
    cout<<posfix.top()<<endl;
}


int main()
{
    string exp;
    getline(cin, exp);

    solve(exp);
    return 0;
}