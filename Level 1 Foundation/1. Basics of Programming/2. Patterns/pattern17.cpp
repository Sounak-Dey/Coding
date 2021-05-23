#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i,j;
    int sp=n/2;
    int st=1;
    for(i = 1;i<=(n/2 + 1);i++)
    {
        for(j = 1; j<=n/2 ; j++)
        {
            if(i==n/2 +1)
            {
                cout<<"*\t";
            }
            else    cout<<"\t";
        }
        for(j=1; j<=st; j++)
        {
            cout<<"*\t";
        }
        for(j=1;j<=sp;j++)
        {
            cout<<"\t";
        }

        cout<< endl;
        st++;
        sp--;
    }
    st--;
    for(i = 1;i<=(n/2);i++)
    {
        st--;
        sp++;
        for(j = 1; j<=n/2 ; j++)
        {
            cout<<"\t";
        }
        for(j=1; j<=st; j++)
        {
            cout<<"*\t";
        }
        for(j=1;j<=sp;j++)
        {
            cout<<"\t";
        }

        cout<< endl;

    }
}