/*

*				*	
*				*	
*		*		*	
*	*		*	*	
*				*	

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i,j;
    int st1=n/2;
    int st2=n/2+2;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==1 || j==n)
            {
                cout<<"*\t";
            }
            else if(i>=(n/2+1) && (i+j==n+1 || i==j))
            {
                cout<<"*\t";
            }
            else
                cout<<"\t";
        }
        cout<<endl;
    }
    return 0;
}