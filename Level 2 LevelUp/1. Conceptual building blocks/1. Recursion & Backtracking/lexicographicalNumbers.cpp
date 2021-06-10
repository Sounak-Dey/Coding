#include <bits/stdc++.h>
using namespace std;

void ln(int i, int n)
{
    if(i>n)
        return;
        
    cout<<i<<endl;
    
    for(auto j=0; j<10; j++)
        ln((i*10 + j), n);
}


int main()
{
    int n;
    cin>>n;

    for(auto i=1; i<10; i++)
        ln(i, n);

    return 0;
}