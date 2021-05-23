/*

*       *       *       *                       *
                        *                       *
                        *                       *
*       *       *       *       *       *       *
*                       *
*                       *
*                       *       *       *       *

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i,j;
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            for(j=1;j<=(n/2+1);j++)
            {
                cout<<"*\t";
            }

            for(j=1;j<=(n/2-1);j++)
            {
                cout<<"\t";
            }
            cout<<"*\t";

            cout<<endl;
        }

        else if(i==n)
        {
            cout<<"*\t";
            for(j=1;j<=(n/2-1);j++)
            {
                cout<<"\t";
            }
            for(j=1;j<=(n/2+1);j++)
            {
                cout<<"*\t";
            }
            cout<<endl;
        }

        else
        {
            if(i<=n/2)
            {
                for(j=1;j<=n/2;j++)
                {
                    cout<<"\t";
                }
                cout<<"*\t";
                for(j=1;j<=(n/2-1);j++)
                {
                    cout<<"\t";
                }
                cout<<"*\t";

                cout<<endl;
            }
            else if(i==(n/2+1))
            {
                for(j=1;j<=n;j++)
                {
                    cout<<"*\t";
                }
                cout<<endl;
            }
            else
            {
                cout<<"*\t";

                for(j=1;j<=(n/2-1);j++)
                {
                    cout<<"\t";
                }

                cout<<"*\t";

                for(j=1;j<=n/2;j++)
                {
                    cout<<"\t";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}