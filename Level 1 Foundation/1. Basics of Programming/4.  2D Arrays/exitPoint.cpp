#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    int i,j,d;

    cin>>n>>m;
    vector<vector<int>> a(n, vector<int> (m));
    
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin>>a[i][j];
    
    
    i = 0;
    j = 0;
    d = 0;

    while((i>=0 && i<n) && (j>=0 && j<m))
    {
        d = (d + a[i][j]) % 4;

        if(d==0)
            j++;
        else if(d==1)
            i++;
        else if(d==2)
            j--;
        else
            i--;
    }

    
    if(i<0)
    {
        i++;
        cout<<i<<"\n"<<j;
    }
    else if(j<0)
    {
        j++;
        cout<<i<<"\n"<<j;
    }
    if(i==n)
    {
        i--;
        cout<<i<<"\n"<<j;
    }
    if(j==m)
    {
        j--;
        cout<<i<<"\n"<<j;
    }


    return 0;
}