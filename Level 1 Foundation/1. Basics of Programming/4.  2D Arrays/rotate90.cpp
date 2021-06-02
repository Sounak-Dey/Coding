#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int i, j, t;

    cin>>n;

    vector<vector<int>> a(n, vector<int> (n));

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            cin>>a[i][j];

    //transpose
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }

    //reverse columns
    for(i=0; i<n; i++)
    {
        int l = 0;
        int r = n-1;

        while(l<r)
        {
            t = a[i][l];
            a[i][l] = a[i][r];
            a[i][r] = t;
            
            l++;
            r--;
        }
    }

    //display
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}