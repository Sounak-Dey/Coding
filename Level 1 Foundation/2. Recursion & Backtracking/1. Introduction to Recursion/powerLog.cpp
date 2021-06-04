#include<bits/stdc++.h>
using namespace std;

int powerLogarithmic(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return (powerLogarithmic(x, n/2) * powerLogarithmic(x, n/2));
    else if(n%2 == 1)
        return (x * powerLogarithmic(x, n/2) * powerLogarithmic(x, n/2));
    
}

int main()
{
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);

    return 0;
}