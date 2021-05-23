#include <iostream>
using namespace std;

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
            if(i==0 && j==0) cout<<a<<"\t";
            else if(i>=j)
            {
                cout<<b<<"\t";
                // a=b;
                // b=a+b;
                c=a;
                a=b;
                b=b+c;

            }
            else cout<<"\t";
        }

        cout<<endl;
    }

}