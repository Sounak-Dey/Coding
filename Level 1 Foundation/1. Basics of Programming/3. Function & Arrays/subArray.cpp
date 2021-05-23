#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    
    // write your code here
    for(int i=0; i<n; i++)
    {
        for(int k=i;k<n;k++)
        {
            for(int j=i; j<=k; j++)
            {
                cout<<arr[j]<<"\t";
            }
            cout<<endl;
        }
    }
    return 0;
}