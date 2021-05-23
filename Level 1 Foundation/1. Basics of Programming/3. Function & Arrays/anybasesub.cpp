#include <bits/stdc++.h>
using namespace std;

void anybasesub(int b, int n1, int n2)
{
    int bw=0;

    int d1,d2,s,c,i;
    int rv = 0,p=1;
    c=0;

    while(n1 || n2 || bw)
    {
        d2 = n2%10;
        d1 = n1%10;
    
        if((d2-bw)<d1)
        {
            d2 = d2 +b;
            s = d2-bw - d1;
            bw = 1;
        }
        else
        {
            s = d2-bw - d1;
            bw=0;
        } 
        
        n1=n1/10;
        n2=n2/10;

        rv = rv + s*p;
        p = p*10;
    }    

    cout<<rv<<endl;
}

int main()
{
    int n1, n2, b;

    cin>>b>>n1>>n2;

    anybasesub(b, n1, n2);

    return 0;
}