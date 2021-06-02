#include<iostream>

using namespace std;

int main()
{
    
    int i,j,n;
    
    cin>>n;
    
    
    int sp = n/2;
    int st = 1;
    
    for(i=0;i<n/2;i++)
    {
        
        
        
        for(j=0;j<sp;j++)
        {
                
            cout<<"\t";
            
        }
        
        for(j=st;j>0;j--)
        {
            
            cout<<"*\t";
            
        }

		cout<<endl;
        
        sp--;
        st += 2;
        
    }
    
    
    sp = 0;
    st = n;
    
        for(i=n/2;i<n;i++)
    {
        
        
        
        for(j=0;j<sp;j++)
        {
                
            cout<<"\t";
            
        }
        
        for(j=st;j>0;j--)
        {
            
            cout<<"*\t";
            
        }

		cout<<endl;
        
        sp++;
        st -= 2;
        
    }
    
    return 0;
    
}