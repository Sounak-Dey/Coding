#include <bits/stdc++.h>
using namespace std;

int freq(long long int n, int d)
{
    long long m;
    int c=0;

    while(n)
    {
        m = n%10;
        if(m==d)
            c++;
        
        n=n/10;
    }

    return c;
}

int main()
{
    long long int n;
    int d,c;
    cin>>n>>d;

    c = freq(n,d);

    cout<<c<<endl;

    return 0;
}