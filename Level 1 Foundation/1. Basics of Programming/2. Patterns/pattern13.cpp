#include <iostream>
using namespace std;

int factorial(int n)
{
    int p=1;

    for(int i=1; i<=n; i++)
    {
        p=p * i;
    }
    
    return p;
    
}

int cn(int n, int r)
{
    int p= factorial(n) / ( factorial(r)*factorial(n-r) );
    return p;
}

int main()
{
    int n;
    cin>>n;

    // write code here

    int i,j,a=0,b=1,c;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i>=j)
            {
                cout<<cn(i,j)<<"\t";
            }
            else cout<<"\t";
        }
        cout<<endl;
    }
}