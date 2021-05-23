#include <bits/stdc++.h>
using namespace std;

list <int> convert(int n, int b)
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
    int n,d;
    cin>>n>>d;

    list <int> l = convert(n,d);

    for(list<int> :: iterator i= l.begin(); i!=l.end();i++)
    {
        cout<<*i;
    }
    cout<<endl;
    return 0;
}