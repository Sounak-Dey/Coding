#include<bits/stdc++.h>
using namespace std;

void toh(int n, int t1, int t2, int t3)
{
    if(n==0)
        return;
    else if(n>0)
    {
        toh(n-1, t1, t3, t2);
        cout<<n<<"["<<t1<<" -> "<<t2<<"]"<<endl;
        toh(n-1, t3, t2, t1);
    }
}

int  main() 
{

    int n;cin>>n;
    int n1,n2,n3;cin>>n1>>n2>>n3;
    toh(n, n1, n2, n3);

    return 0;
}