#include<bits/stdc++.h>
using namespace std;

int power(int x,int n)
{
    if(n==0)
        return 1;
    else if(n>0)
        return (x * pow(x,n-1));
}


int main()
{
    int n,x; cin>>x>>n;
    cout<<power(x,n);

    return 0;
}
