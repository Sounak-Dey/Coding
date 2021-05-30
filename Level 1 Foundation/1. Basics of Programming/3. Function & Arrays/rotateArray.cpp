#include<iostream>
using namespace std;

void rotate(int* arr, int n, int k){
   // write your code here
   
   
   int i,j=0;
   
   
   if(k>=0)
   {
        k = k%n;
        int *b = new int[k];

        for(i=(n-k); i<n; i++)
        {
            b[j++] = arr[i];
        }
        for(i=0;i<(n-k); i++)
        {
            arr[i+k] = arr[i];
        }
        for(i=0; i<k; i++)
        {
            arr[i] = b[i];
        }

        delete[] b;
   }
   else if(k<0)
   {
       k = k*(-1);
       k = k%n;
       int *b = new int[k];

       for(i=0; i<k; i++)
       {
           b[j++] = arr[i];
       }
       for(i=k; i<n; i++)
       {
           arr[i-k] = arr[i];
       }
       for(i=(n-k), j=0; i<n; i++, j++)
       {
           arr[i]= b[j];
       }

       delete[] b;
   }
   

    
}

void display(int* arr, int n)
{
    for(int i = 0 ; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n, r;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>r;
    
    rotate(arr,n,r);
    display(arr,n);

    delete[] arr;
}