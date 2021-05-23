#include <bits/stdc++.h>
using namespace std;

 int dif(int *a1, int n1, int *a2, int n2)
{
    int a=0,b=0,p=0;
    for(int  i= n1-1; i>=0; i--)
    {
        a += a1[i]*pow(10,p++); 
    }
   // cout<<a<<endl;
    p=0;
    
    for(int j= n2-1; j>=0; j--)
    {
        b += a2[j]*pow(10,p++); 
    }
   // cout<<b<<endl;

    return(b-a);
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

    int s = dif(a1, n1,a2,n2);
   // int m=n2 ;
   int d=s;
    int n=0;
    

    while(d)
    {
        n++;
        d=d/10;
    }
    int* a = new int[n];
    
    int m=n+1;
    while(s>0)
    {
        a[n--] = s%10;
        s=s/10;
    }
    n=m;
    for(int i=1; i<n; i++)
    {
        cout<<a[i]<<endl;
    }

    delete[] a1;
    delete[] a2;
    delete[] a;
    return 0;
}