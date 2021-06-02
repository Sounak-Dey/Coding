#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, m1, n2, m2;
    int i,j;

    cin>>n1>>m1;

    int **a = new int *[n1];
    for(i=0; i<n1; i++) 
        a[i] = new int[m1];

    for(i=0; i<n1; i++)
        for(j=0; j<m1; j++)
            cin>>a[i][j];


    cin>>n2>>m2;

    int **b = new int *[n2];
    for(i=0; i<n2; i++) 
        b[i] = new int[m2];

    for(i=0; i<n2; i++)
        for(j=0; j<m2; j++)
            cin>>b[i][j];

    
    if(m1==n2)
    {
        int **p = new int *[n1];
        for(i=0; i<n1; i++) 
            p[i] = new int[m2];

        for(i=0; i<n1; i++)
        {
            for(j=0; j<m2; j++)
            {
                p[i][j] = 0;

                for(int k=0; k<n2; k++)
                {
                    p[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        for(i=0; i<n1; i++)
        {
            for(j=0; j<m2; j++)
                cout<<p[i][j]<<" ";
            
            cout<<"\n";
        }
            


        for(int i=0;i<n1;i++)    
            delete [] p[i];   
        delete [] p;        
    }
    else
    {
        cout<<"Invalid input"<<endl;
    }

    for(int i=0;i<n1;i++)    //To delete the inner arrays
      delete [] a[i];   
    delete [] a;             // to delete the outer array of pointers

    for(int i=0;i<n2;i++)    //To delete the inner arrays
      delete [] b[i];   
    delete [] b;
    

    return 0;
}