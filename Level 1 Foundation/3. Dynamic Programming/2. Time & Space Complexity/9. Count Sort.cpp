#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>
using namespace std;

void print(vector<int> &arr) 
{
    for(int i = 0; i < arr.size(); i++)
        cout<<(arr[i])<<endl;
    
    cout<<endl;
}

// used when the range of values stored in array is small compared to the number of elements in the array
// as it uses freq mapping and is a stable sort algorithm
void countSort(vector<int> &arr, int minv, int maxv)
{
    int range = maxv - minv + 1;
    vector<int> freqArr(range, 0), ans(arr.size());

    for(int i=0; i<arr.size(); i++) // mapping freq
        freqArr[arr[i] - minv]++;

    for(int i=1; i<freqArr.size(); i++) //converting to prefix-sum array
        freqArr[i] += freqArr[i-1];
    
    for(int i=0; i<freqArr.size(); i++) //converting to 0th index positioning
        freqArr[i]--;

    for(int i=arr.size()-1; i>=0; i--)  // placing elements in sorted form, into the 'ans' array using freqArray
    {                                   // we traverse the array from the end to maintain stability of the elements i.e to stable sort
        ans[freqArr[arr[i] - minv]] = arr[i];
        freqArr[arr[i] - minv]--;
    }
    
    print(ans);
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    auto minv = *min_element(arr.begin(), arr.end());
    auto maxv = *max_element(arr.begin(), arr.end());

    countSort(arr, minv, maxv);
    return 0;
}