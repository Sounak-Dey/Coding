#include <bits/stdc++.h>
using namespace std;

void anybaseadd(int b,int n1, int n2)
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

    cout<<rv<<endl;
}

int main()
{
    int b, n1, n2;
    cin>>b>>n1>>n2;

    anybaseadd(b, n1, n2);

    return 0;
}