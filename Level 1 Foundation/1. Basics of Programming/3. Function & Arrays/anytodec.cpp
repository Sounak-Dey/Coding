#include <bits/stdc++.h>
using namespace std;

int convert(long long n, int b)
{
    int d=0,m,i=0,p;

    while(n)
    {
        p =  pow(b,i) ;
        d = d + (p * (n%10));
        n=n/10;
        i++;
    }
    return d;
}

int main()
{
    long long n;
    int b;
    cin>>n>>b;

    cout<<convert(n,b)<<endl;

    return 0;
}