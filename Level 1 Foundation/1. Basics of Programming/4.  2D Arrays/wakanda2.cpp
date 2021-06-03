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

    int p = n;
    int diff = 0;

    while(diff<a.size())
    {
        for(i=0,j=diff; j<a[0].size(); i++,j++)
        {
            cout<<a[i][j]<<endl;
        }
        diff++;
    }


    // while(p>0) //TLE error
    // {
    //     for(i=0; i<p; i++)
    //     {
    //         for(j=i; j<n; j++)
    //         {
    //             if(j = i+diff)
    //                 cout<<a[i][j]<<endl;
    //         }
    //     }

    //     diff++;
    //     p--;
    // }

    return 0;
}