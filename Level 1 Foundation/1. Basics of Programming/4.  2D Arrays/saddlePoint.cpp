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

    int r = 0;
    while(r < a.size())
    {
        int minc = 0;

        for(j=1; j<a[0].size(); j++)
        {
            if(a[r][j] < a[r][minc])
                minc = j;
        }

        bool flag = true;
        for(i=0; i<a.size(); i++)
        {
            if(a[i][minc] > a[r][minc])
            {
                flag = false;
                break;
            }
        }

        if(flag == true)
        {
            cout<<a[r][minc];
            return 0;
        }

        r++;
    }

    cout<<"Invalid input";
    return 0;
    
}