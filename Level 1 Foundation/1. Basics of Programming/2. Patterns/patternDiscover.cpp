//              1	
// 		    2	1	2	
// 	    3	2	3	2	3	
//  4	3	4	3	4	3	4	
// 	    3	2	3	2	3	
// 		    2	1	2	
// 			    1


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n;   
    cin>>n;
    
    int sp = n/2;
    int st = 1;
    int r = 1,c;

    for(i=0;i<n/2;i++)
    {
        c=r;    
        for(j=0;j<sp;j++)
        {           
            cout<<"\t";   
        }
        
        for(j=st;j>0;j--)
        {
            if(c<=st/2)
                cout<<c++<<"\t";
            else
                cout<<c--<<"\t";       
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
        
        for(j=st;j>0;j--)
        {
            if(c<=st/2)
                cout<<c++<<"\t";
            else
                cout<<c--<<"\t";   
        }

		cout<<endl;
        
        sp++;
        st -= 2;
        r--;
    }   
}