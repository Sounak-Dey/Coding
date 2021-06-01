#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    // int** seq=new int* [n];
    int **a = new int*[n];

    for(int i=0; i<n; i++)
    {
        a[i] = new int[m];
    }

    for(int i(0); i<n; i++)
    {
        for(int j(0); j<m; j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i(0); i<n; i++)
    {
        for(int j(0); j<m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }


    for(int i=0;i<n;i++)    //To delete the inner arrays
      delete[] a[i];   

    delete[] a;             // to delete the outer array of pointers

    return 0;
}