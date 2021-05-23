
/*

*	*	*		*	*	*	
*	*				*	*	
*						*	
*	*				*	*	
*	*	*		*	*	*	

*/

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    //write your code here

    //forward half
    for(int i=n; i>0; i-=2)
    {
        for(int j=0; j<(i/2 +1); j++)
        {
            cout<<"*\t";
        }
        
        for(int j=0; j<((n-i) +1); j++)
        {
            cout<<"\t";
        }

        for(int j=0; j<(i/2 +1); j++)
        {
            cout<<"*\t";
        }

        cout<<endl;
    }

    //reverse
    for(int i=3; i<=n; i+=2)
    {
        for(int j=0; j<(i/2 +1); j++)
        {
            cout<<"*\t";
        }
        
        for(int j=0; j<((n-i) +1); j++)
        {
            cout<<"\t";
        }

        for(int j=0; j<(i/2 +1); j++)
        {
            cout<<"*\t";
        }

        cout<<endl;
    }
}