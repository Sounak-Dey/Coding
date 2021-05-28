#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int *a = new int[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    // stringstream s(a);
    // int x;

    // s>>x;

    int num = atoi(a);

    //cout<<x<<endl;
    cout<<num<<endl;

    delete[] a;

    return 0;
}