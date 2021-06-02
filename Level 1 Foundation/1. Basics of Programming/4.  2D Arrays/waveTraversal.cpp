#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    int i, j;

    cin>>n>>m;

    int **a = new int *[n];
    for(i=0; i<n; i++)
        a[i] = new int[m];

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin>>a[i][j];
    

    for(j=0; j<m; j++)
    {
        if(j%2 == 0)
            for(i=0; i<n; i++)
                cout<<a[i][j]<<"\n";
        else
            for(i=n-1; i>=0; i--)
                cout<<a[i][j]<<"\n";

    }

    for(i=0; i<n; i++)
        delete[] a[i];
    delete[] a;
}