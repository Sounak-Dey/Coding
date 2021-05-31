# include <bits/stdc++.h>
using namespace std;



void firstIndex(int *a, int n, int d)
{
    int l = 0;
    int h = n-1;
    int m = (l + h)/2;
    int min=-1,c=0;
    
    while(l<=h)
    {
        if(d>a[m])
        {
            l = m+1;
        }
        else if(d<a[m])
        {
            h = m-1;
        }
        else
        {
            c++;
            min = m;
            h = m-1;
        }
        
        m = (l + h)/2;
    }

    cout<<min<<endl;

}


void lastIndex(int *a, int n, int d)
{
    int l = 0;
    int h = n-1;
    int m = (l + h)/2;
    int max=-1,c=0;
    
    while(l<=h)
    {
        if(d>a[m])
        {
            l = m+1;
        }
        else if(d<a[m])
        {
            h = m-1;
        }
        else
        {
            c++;
            max = m;
            l = m+1;
        }
        
        m = (l + h)/2;
    }

    cout<<max<<endl;

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

    firstIndex(arr, n, data);
    lastIndex(arr, n, data);

    delete[] arr;

    return 0;
    
}