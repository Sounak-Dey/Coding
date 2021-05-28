#include <iostream>
using namespace std;

int main()
{
    // int *arr = new int[5];
    // int i=0;

    // while(i<5)
    // {
    //     cin>>arr[i];
    //     i++;
    // }
    // int *two = arr;
    // two[2] = 10;
    // i=0;

    // while(i<5)
    // {
    //     cout<<arr[i]<<"\t";
    //     i++;
    // }
    // cout<<endl;
    // delete[] arr;
    // return 0;
    
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i = 0 ; i < n; i++)
    {
        cin>>a[i];
    }

    cout<< sizeof(a)<<endl;
    delete[] a;
    return 0;
}
