#include<iostream>
using namespace std;

void reverse(int * arr, int left, int right)
{
    
    while(left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
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
    reverse(arr,0,n-1);
    display(arr,n);
    return 0;
}