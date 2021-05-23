/*

1	
2	3	
4	5	6	
7	8	9	10	
11	12	13	14	15

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    // write code here

    int i,j,c=1;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i>=j)
            {
                cout<<c++<<"\t";
            }
            else cout<<"\t";
        }

        cout<<endl;
    }

}