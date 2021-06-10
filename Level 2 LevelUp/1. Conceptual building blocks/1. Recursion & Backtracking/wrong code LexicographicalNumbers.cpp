#include <bits/stdc++.h>
using namespace std;


// error coz this code prints 1 - 9 even the input is smaller than 9
// cheking needs to be done early at the start

void ln(int i, int n)
{
    int p = i;
    cout<<p<<endl;
    
    for(auto i=0; i<10; i++)
    {
        if((p*10 + i) <= n)
            ln((p*10 + i), n);
        else return;
    }
}


int main()
{
    int n;
    cin>>n;

    for(auto i=1; i<10; i++)
        ln(i, n);

    return 0;
}