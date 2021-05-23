/*

*       *       *       *       *       *       *       *       *
        *                                               *
                *                               *
                        *               *
                                *
                        *       *       *
                *       *       *       *       *
        *       *       *       *       *       *       *
*       *       *       *       *       *       *       *       *

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i,j;
    int spx,sp,st;
    sp = 1;
    spx = n-4;
    for(i=1;i<=n;i++)
        cout<<"*\t";
    cout<<endl;

    for(i=2;i<=(n/2 +1);i++)
    {
        for(j=1;j<=sp;j++) // print spaces
        {
            cout<<"\t";
            
        }

        cout<<"*\t";    // print star
        
        for(j=1;j<=spx;j++) //print spaces
        {
            cout<<"\t";
        }

        if(i<(n/2 +1))  //print star
        {
            cout<<"*\t";
        }
        
        cout<<endl;

        sp++;
        spx -=2;
    }

    sp = n/2 -1;
    st = 3;
    for(i=(n/2+2);i<=n;i++)
    {
        for(i=0;i<sp;i++)
        {
            cout<<"\t";
        }

        for(i=0;i<st;i++)
        {
            cout<<"*\t";
        }
        cout<<endl;

        sp--;
        st+=2;
    }

    return 0;
}
