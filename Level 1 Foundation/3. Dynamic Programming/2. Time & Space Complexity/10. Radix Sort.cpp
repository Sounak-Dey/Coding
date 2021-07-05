#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int> &arr) 
{
    for(int i = 0; i < arr.size(); i++)
        cout<<(arr[i])<<" ";
    
    cout<<endl;
}

void countSort(vector<int> &arr, int exp)
{
    vector<int> freqArr(10, 0), ans(arr.size());

    for(int i=0; i<arr.size(); i++) // mapping freq
        freqArr[(arr[i]/exp) % 10]++;

    for(int i=1; i<freqArr.size(); i++) //converting to prefix-sum array
        freqArr[i] += freqArr[i-1];
    
    for(int i=0; i<freqArr.size(); i++) //converting to 0th index positioning
        freqArr[i]--;

    for(int i=arr.size()-1; i>=0; i--)  // placing elements in sorted form, into the 'ans' array using freqArray
    {                                   // we traverse the array from the end to maintain stability of the elements i.e to stable sort
        ans[ freqArr[(arr[i]/exp) % 10] ] = arr[i];
        freqArr[(arr[i]/exp) % 10]--;
    }
    
    cout<<"After sorting on "<<exp<<" place -> ";
    print(ans);
    
    for(int i=0; i<ans.size(); i++)
        arr[i] = ans[i];
        
}

void radixSort(vector<int> &arr)
{
    int maxv = *max_element(arr.begin(), arr.end());

    int exp = 1;
    while(exp <= maxv)
    {
        countSort(arr, exp);
        exp *= 10;
    }
}



int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    radixSort(arr);
    print(arr);
    return 0;
}