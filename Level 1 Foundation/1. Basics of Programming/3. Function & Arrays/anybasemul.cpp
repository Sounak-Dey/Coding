#include <bits/stdc++.h>
using namespace std;

int anybaseadd(int b,int n1, int n2)
{
    int d1,d2,s,c,i;
    int rv = 0,p=1;
    c=0;
    while(n1 || n2 || c)
    {
        d1 = n1%10;
        d2 = n2%10;

        s = d1 + d2 + c;
    
        if(s>=b)
        {
            c = s/b;
            s=s%b;
        }
        else c=0;

        n1=n1/10;
        n2=n2/10;

        rv = rv + s*p;
        p = p*10;
    }    

    return rv;
}

int multiply(int n1, int d, int b)
{
    int rv=0,pd,c=0,d1,p=1;
    while(n1 || c)
    {
        d1 = n1%10;
        pd = d*d1 + c;

        if(pd>=b)
        {
            c = pd/b;
            pd = pd%b;
        }
        else c = 0;
        
        n1 = n1/10;

        rv = rv + pd*p;
        p = p*10;
    }

    return rv;
}

int anybasemul(int n1, int n2, int b)
{
    int d,m,num[10],p=1,i=0;

    while(n2)
    {
        d=n2%10;
        m = multiply(n1, d, b);

        num[i] = m*p;
        p=p*10;
        i++;

        n2 = n2/10;
    }
    num[i]=-1;

    for(i=1; num[i]!=-1; i++)
    {
        num[i] = anybaseadd(b, num[i-1], num[i]);
    }
    i--;

    return num[i]; 
}

int main()
{
    int b, n1, n2;
    cin>>b>>n1>>n2;

    cout<<anybasemul(n1, n2, b)<<endl;
    return 0;
}