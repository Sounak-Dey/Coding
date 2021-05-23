#include <bits/stdc++.h>
using namespace std;

int anytodec(long long n, int b)
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

list <int> dectoany(int n, int b)
{
    int m,c;
    list <int> l;
    m=n;
    while(n)
    {
        c = n%b;
        l.push_front(c);
        n=n/b;
    }

    return l;
}

int main()
{
    long long n;
    int b1,b2;
    cin>>n>>b1>>b2;

    int d = anytodec(n,b1);
    
    list <int> l = dectoany(d,b2);

    for(list<int> :: iterator i= l.begin(); i!=l.end();i++)
    {
        cout<<*i;
    }
    cout<<endl;
    return 0;
}