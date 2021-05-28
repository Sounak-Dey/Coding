#include <bits/stdc++.h>
using namespace std;

void sum(int *a1, int n1, int *a2, int n2)
{
    int i=n1-1, j=n2-1, c=0;
    int n=(n1>n2)?n1:n2 ;
    n-=1;
    int *s= new int[n] ;
    
    while(n>=0)
    {
        s[n] = c;
        if(i>=0)
            s[n] += a1[i];  
        if(j>=0) 
            s[n] += a2[j];   

        c = s[n] / 10;
        s[n] = s[n] % 10;

        n--;
        j--;
        i--;
    }

    if(c!=0)
        cout<<c<<endl;
    
    i=0;
    n=(n1>n2)?n1:n2 ;

    while(i<n)
    {
        cout<<s[i++]<<endl;
    }

    delete[] s;
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

    sum(a1, n1, a2, n2);


    delete[] a1;
    delete[] a2;

    return 0;
}