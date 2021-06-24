#include<iostream>
using namespace std;

int solve(int n)
{
    int sB = 1, sS = 1; // stores count of appropriate arrangements ending with space(sS) and building(sB)
    int nsB, nsS;
    int i=2;    //as for i=1 sB=1 & sS=1
    
    while(i<=n)
    {
        nsB = sS;
        nsS = sB + sS;

        i++;
        sB = nsB;
        sS = nsS;
    }

    if(n==0)
        return 0;
    else
        return (sB + sS);
}

int main()
{
    int n;
    cin>>n;
    
    long long ans = solve(n);
    cout<<ans*ans;

    return 0;
}