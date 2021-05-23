#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n;   
    cin>>n;
    
    int sp = n/2;
    int st = 1;
    int r = 1,c,ctr;

    for(i=0;i<n/2;i++)
    {
        c=r;    
        for(j=0;j<sp;j++)
        {           
            cout<<"\t";   
        }
        ctr = 0;
        for(j=st;j>0;j--)
        {
            //int ctr = 0;
            if(ctr < st/2)
                cout<<c++<<"\t";
            else 
                cout<<c--<<"\t";

            ctr++;
        }

		cout<<endl;
        
        sp--;
        st += 2;
        r++;
    }
    
    sp = 0;
    st = n;
    r = n/2 +1;

    for(i=n/2;i<n;i++)
    {   
        c=r; 
        for(j=0;j<sp;j++)
        {           
            cout<<"\t";   
        }
        ctr = 0;
        for(j=st;j>0;j--)
        {
            //int ctr = 0;
            if(ctr < st/2)
                cout<<c++<<"\t";
            else 
                cout<<c--<<"\t";

            ctr++;   
        }

		cout<<endl;
        
        sp++;
        st -= 2;
        r--;
    }   
}