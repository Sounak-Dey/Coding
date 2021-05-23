#include <bits/stdc++.h>
using namespace std;

void bar(int *a, int n, int max)
{
    int i,j;

    for(i=max;i>0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]>=i)
            {
                cout<<"*\t";
            }
            else cout<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    int n, max, i;
    cin>>n;

    int *a = new int[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        
    }
    max = a[0];

    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        max = a[i];
    }

    bar(a, n, max);
    
    delete[] a;
    return 0;
}