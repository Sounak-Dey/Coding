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
    
    cout<<endl;
}

int partition(vector<int> &arr, int pivot, int l, int r)
{
    // 0 - (j-1) -> store elements less and equal to than pivot 
    // j - (i-1) -> store elements more than pivot 
    // i - rest -> stores the unexlpored array

    cout<<"pivot -> "<<pivot<<endl;
    int i=l, j=l;

    while(i<=r)
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
    cout<<"pivot index -> "<<(j-1)<<endl;
    return(j-1);
}

int quickSelect(vector<int> &arr, int l, int r, int ei)
{
    // if(l>=r)
    //     return arr[l];

    int pivot = arr[r];
    int pi = partition(arr, pivot, l, r);

    if(pi == ei)
        return arr[pi];

    else if(pi > ei)
        quickSelect(arr, l, pi-1, ei);

    else if(pi < ei)
        quickSelect(arr, pi+1, r, ei);
}



int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int k;
    cin>>k;

    cout<<quickSelect(arr, 0, arr.size()-1, k-1);
    // print(arr);
    return 0;
}