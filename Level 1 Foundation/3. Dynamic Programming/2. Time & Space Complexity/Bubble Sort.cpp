#include<iostream>
#include<vector>
using namespace std;

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout<<"Swapping " << arr[i] << " and " << arr[j]<<endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// return true if ith element is smaller than jth element
bool isSmaller(vector<int> &arr, int i, int j)
{
    cout<<"Comparing " << arr[i] << " and " << arr[j]<<endl;
    if(arr[i] < arr[j]) 
        return true;
    else 
        return false;
}

void bubbleSort(vector<int> &arr)
{
    for(int i=arr.size()-1; i>0; i--)
        for(int j=0; j<i; j++)
        {
            if(isSmaller(arr, j+1, j))
                swap(arr, j+1, j);
        }
}

void print(vector<int> &arr) 
{
    for(int i = 0; i < arr.size(); i++)
        cout<<(arr[i])<<endl;
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    bubbleSort(arr);
    print(arr);
    return 0;
}


