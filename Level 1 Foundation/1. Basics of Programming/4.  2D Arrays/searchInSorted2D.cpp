#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    int i,j;

    cin>>n;

    vector<vector<int>> a (n, vector<int> (n));

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            cin>>a[i][j];

    int x;
    cin>> x;

    i = 0;
    j = a[0].size() - 1;

    while(i<a.size() && j>=0)
    {
        if(a[i][j] > x)
            j--;
        else if(a[i][j] < x)
            i++;
        else
        {
            cout<<i<<endl<<j;
            return 0;
        }
    }

    cout<<"Not Found";
    return 0;
}