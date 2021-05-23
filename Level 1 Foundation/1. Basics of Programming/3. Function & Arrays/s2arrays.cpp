#include <bits/stdc++.h>
using namespace std;

// void sum(int *a1, int n1, int *a2, int n2)
// {
//     int i=n1-1, j=n2-1, c=0;
//     int n=(n1>n2)?n1:n2 ;
//     n-=1;
//     int *s= new int[n] ;
//     while(n>=0)
//     {
//         s[n]= a1[i] + a2[j] +c ;
//         if(s[n]>9)
//         {
//             s[n] = s[n] % 10;
//             c=1;
//         }
//         else c=0;
//         n--;
//         j--;
//         i--;
//     }
//     i=0;
//     n=(n1>n2)?n1:n2 ;
//     while(i<n)
//     {
//         cout<<s[i++];
//     }
//     cout<< endl;
//     delete[] s;
// }

 int sum(int *a1, int n1, int *a2, int n2)
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

    return(a+b);
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

    int s = sum(a1, n1,a2,n2);
    int m=(n1>n2)?n1:n2 ;
    int n=m-1;
    int* a = new int[n];

    while(s)
    {
        a[n--] = s%10;
        s=s/10;
    }
    n=m;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<endl;
    }

    delete[] a1;
    delete[] a2;
    delete[] a;
    return 0;
}