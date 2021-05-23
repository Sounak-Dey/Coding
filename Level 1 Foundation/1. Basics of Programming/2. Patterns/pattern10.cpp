/*

		*	
	*		*	
*				*	
	*		*	
		*	


*/
#include <iostream>
using namespace std;

int main()
{
    int n, a=0, b=0;
    cin>>n;

    // printing top half
    a=n/2;
    b=n/2;
    for(int i=0; i<=n/2; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j==a || j==b)   cout<<"*\t";
            else cout<<"\t";

        }
        a--;
        b++;

        cout<<endl;
    }

    // printing bottom half
    a=1;
    b=n-2;
    for(int i=(n/2 -1); i>=0; i--)
    {
        for(int j=0; j<n; j++)
        {
            if(j==a || j==b)   cout<<"*\t";
            else cout<<"\t";

        }
        a++;
        b--;

        cout<<endl;
    }
}