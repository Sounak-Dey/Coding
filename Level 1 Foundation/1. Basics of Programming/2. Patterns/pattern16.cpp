/*

1												1	
1	2										2	1	
1	2	3								3	2	1	
1	2	3	4						4	3	2	1	
1	2	3	4	5				5	4	3	2	1	
1	2	3	4	5	6		6	5	4	3	2	1	
1	2	3	4	5	6	7	6	5	4	3	2	1	

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>> n;
    int i,j;
    int sp,st,c;

    sp = 2*n - 3;
    st = 1;
    
    int t = st;
    
    for(i=1;i<=n;i++)
    {
        c = 1;

        for(int j=1;j<=st;j++)
        {
            cout<<c++<<"\t";
        }

        for(int j =1;j<=sp;j++)
        {
            cout<< "\t";
        }

        if(i==n)
        {
            st--;
            c--;
        }
            

        for(int j=1;j<=st;j++)
        {
            cout<<--c<<"\t";
        }

        st++;
        sp -=2;

        cout<<endl;
    }
}