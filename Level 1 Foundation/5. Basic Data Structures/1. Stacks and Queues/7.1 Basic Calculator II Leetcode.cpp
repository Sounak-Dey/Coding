#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int precedence(char op)
    {
        if(op == '+'  ||  op == '-')
            return 1;
        else if(op == '*'  ||  op == '/')
            return 2;
        else 
            return 0;
    }

    
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
    
    
    int calculate(string exp) {
        int n = exp.length();
        stack<char> opt;
        stack<int> opnd;

        for(int i=0; i<n; i++)
        {
            if(isdigit(exp[i]))     // to handle multiple digits
            {
                int s = 0, c = 0;
                while(isdigit(exp[i]))
                {
                    s = 10*s + (exp[i]-'0');

                    if(c>0)
                        opnd.pop();
                    opnd.push(s);
                    i++;
                    c++;
                }
                s=0;
                c=0;
                i--;    // to compensate the extra i++ for the last failed round
            }

            else if(exp[i] == '(')
                opt.push(exp[i]);

            else if(exp[i] == ')') //pop and evaluate till you find '('
            {
                while(opt.top() != '(')
                {
                    char op = opt.top();
                    opt.pop();

                    int v2 = opnd.top();
                    opnd.pop();

                    int v1 = opnd.top();
                    opnd.pop();

                    opnd.push(operate(v1, v2, op));
                }

                opt.pop(); // pop the '('
            }
            else if(exp[i] == '+'  ||  exp[i] == '-'  ||  exp[i] == '*'  ||  exp[i] == '/') 
            {  
                while( !opt.empty()  &&  opt.top() != '('  &&  precedence(opt.top()) >= precedence(exp[i]) )   //pop and evaluate if lower precedence op arrives 
                {
                    char op = opt.top();
                    opt.pop();

                    int v2 = opnd.top();
                    opnd.pop();

                    int v1 = opnd.top();
                    opnd.pop();

                    opnd.push(operate(v1, v2, op));
                }

                opt.push(exp[i]);
            }
        }

        while(opt.empty() == false)
        {
            char op = opt.top();
            opt.pop();

            int v2 = opnd.top();
            opnd.pop();

            int v1 = opnd.top();
            opnd.pop();

            opnd.push(operate(v1, v2, op));
        }

        return opnd.top();
    }
};