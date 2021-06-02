#include<bits/stdc++.h>

using namespace std;

void reverse(int* arr, int n)
{
    int i,j;
    
    if(n%2==0)
    {
        for(i=0,j=n-1; i<n/2,j>=n/2; i++,j--)
        {
            arr[i] = arr[i] + arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
        }
    }
    else
    {
        for(i=0,j=n-1; i<n/2,j>(n/2); i++,j--)
        {
            arr[i] = arr[i] + arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
        }
    }
}

void rotate(int* arr, int n, int k)
{
    k = k%n;
    if(k<0)
    {
        k = k + n;
    }

    int *p1 = new int[n-k];
    int *p2 = new int[k];
    int i,j;

    for(i=0,j=0; i<(n-k); i++,j++)
    {
        p1[j] = arr[i];
    }
   
    for(j=0; i<(n); i++,j++)
    {
        p2[j] = arr[i];
    }

    reverse(p1, n-k);
    reverse(p2, k);
    
    for(i=0,j=0; i<(n-k); i++,j++)
    {
        arr[i] = p1[j];
    }
   
    for(j=0; i<(n); i++,j++)
    {
        arr[i] = p2[j];
    }

    reverse(arr, n);
    
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