#include<iostream>

using namespace std;

void solve(int n)
{
    int s0 = 1, s1 = 1; // stores count of appropriate strings ending with 1(s1) and 0(s0)
    int ns0, ns1;
    int i=2;    //as for i=1 s0=1 & s1=1
    
    while(i<=n)
    {
        ns0 = s1;
        ns1 = s0 + s1;

        i++;
        s0 = ns0;
        s1 = ns1;
    }

    if(n==0)
        cout<< 0;
    else
        cout<<(s0 + s1);
}

int main()
{
    int n;
    cin>>n;
    
    solve(n);
    return 0;
}