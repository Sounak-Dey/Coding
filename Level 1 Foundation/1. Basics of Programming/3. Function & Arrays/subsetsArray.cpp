#include <bits/stdc++.h>
using namespace std;

void subsetsArray(int *a, int n)
{
    unsigned long long p = pow(2, n);
    int i,j;

    for(i=0; i<p; i++)
    {
        int t = i;
        string str = "";
        char ch;

        for( j=n-1; j>=0; j--)
        {
            int r = t % 2;
            
            if(r==0)
            {
                str = "-\t" + str;
            }
            else
            {
                str = to_string(a[j]) + "\t" + str;
            }

            t = t/2 ;
        }

        cout<<str<<endl;
    }
}


int main()
{
    // vector <int> a;
    

    int n,x;
    int *a = new int[n];

    cin>>n;

    for(int i(0); i<n; i++)
    {
        // cin>>x;
        // a.push_back(x);
        cin>>a[i];
    }

    subsetsArray(a, n);

    delete[] a;

    return 0;
}