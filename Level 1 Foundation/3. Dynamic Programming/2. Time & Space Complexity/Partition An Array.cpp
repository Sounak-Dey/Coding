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

void print(vector<int> &arr) 
{
    for(int i = 0; i < arr.size(); i++)
        cout<<(arr[i])<<" ";
}

void partition(vector<int> &arr, int pivot)
{
    // 0 - (j-1) -> store elements less and equal to than pivot 
    // j - (i-1) -> store elements more than pivot 
    // i - rest -> stores the unexlpored array

    int i=0, j=0;

    while(i<arr.size())
    {
        if(arr[i] > pivot) // element gets stored into the greater region
            i++;
        else if(arr[i] <= pivot) // element gets stored into the lesser region
        {
            swap(arr, i, j);
            j++;
            i++;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int pivot;
    cin>>pivot;

    partition(arr, pivot);
    print(arr);
    return 0;
}