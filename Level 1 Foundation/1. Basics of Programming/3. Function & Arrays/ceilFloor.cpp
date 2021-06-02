#include <bits/stdc++.h>
using namespace std;

void ceilFLoor(int *a,int n, int d)
{
    int l = 0;
    int h = n-1;
    int m = (l + h)/2;
    int ceil, floor;

    while(l<=h)
    {
        if(d>a[m])
        {
            floor = a[m];
            l = m + 1;
        }
        else if(d<a[m])
        {
            ceil = a[m];
            h = m - 1;
        }
        else
        {
            ceil = a[m];
            floor = a[m];
            break;
        }

        m = (l+h)/2;
        
    }
    
    cout<<ceil<<endl;
    cout<<floor<<endl;
}


int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int data;
    cin>>data;
    
    ceilFLoor(arr, n, data);

    delete[] arr;
}