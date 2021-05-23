#include<iostream>
using namespace std;

void reverse(int* arr, int n)
{
    // write your code here
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
    int n;
    cin>>n;
    
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
    }
    reverse(arr,n);
    display(arr,n);
    return 0;
}