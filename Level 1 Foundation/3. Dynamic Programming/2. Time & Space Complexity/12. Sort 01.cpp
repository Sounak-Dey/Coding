#include<iostream>
#include<vector>
using namespace std;


void print(vector<int> &arr) 
{
    for(int i = 0; i < arr.size(); i++)
        cout<<(arr[i])<<endl;
}

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// partitioning with pivot = 0
void partition(vector<int> &arr, int pivot, int l, int r)
{
    int i = 0;
    int j = 0;

    while(i <= r)
    {
        if(arr[i] <= pivot)
        {
            swap(arr, i, j);
            j++;
            i++;
        }
        else
            i++;
    }
}

void sort01(vector<int> &arr)
{
    int pivot = 0;
    partition(arr, 0, 0, arr.size()-1);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr)
        cin>>i;
    
    sort01(arr);
    print(arr);
    return 0;
}