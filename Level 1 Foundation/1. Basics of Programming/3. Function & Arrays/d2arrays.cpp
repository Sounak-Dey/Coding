#include <bits/stdc++.h>
using namespace std;

void dif(int *a1, int n1, int *a2, int n2)
{

    int i = n1-1, j = n2-1, bw = 0 ;
    int *d = new int[n2];

    int n = n2-1;

    while(n>=0)
    {
        int a1v = (i>=0)?a1[i]:0;

        if(a2[j]-bw>=a1v)
        {
            d[n] = a2[j] - bw - a1v;
            bw = 0;
        }
        else
        {
            d[n] = a2[j] + 10 - bw - a1v;
            bw = 1;
        }

        n--;
        i--;
        j--;
    }

    i=0;
    
    while(i<n2)
    {
        if(d[i] == 0)
            i++;
        else    
            break;
    }

        
    for(;i<n2;i++)
    {
        cout<<d[i]<<endl;
    }


    delete[] d;
}

int main(){
    int n1, n2;
    cin>>n1;
    int* a1 = new int[n1];
    for(int i = 0 ; i < n1; i++){
        cin>>a1[i];
    }
    
    cin>>n2;
    int* a2 = new int[n2];
    for(int i = 0 ; i < n2; i++){
        cin>>a2[i];
    }

    dif(a1, n1,a2,n2);

    delete[] a1;
    delete[] a2;

    return 0;
}