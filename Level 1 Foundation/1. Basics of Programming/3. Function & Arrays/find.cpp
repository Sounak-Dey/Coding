#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,d,p=-1;

    cin>>n;

    int *a = new int[n];

    for(i=0; i<n;i++)
    {
        cin>>a[i];
    }

    cin>>d;

    for(i=0;i<n;i++)
    {
        if(a[i]==d)
        {
            p=i;
            break;
        }    
        else 
            continue;
    }
    cout<<p<<endl;

    return 0;
}