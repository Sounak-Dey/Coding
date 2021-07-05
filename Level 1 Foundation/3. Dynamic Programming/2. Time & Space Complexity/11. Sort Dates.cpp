#include <iostream>

#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]/10000000 == 0)    // hacky to print the ignored zero of the date at the beginning
        cout<<0<<arr[i]<<endl;
        else
            cout << arr[i] << endl;
    }
    cout << endl;
}

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void countSort(vector<int> &arr, int exp, int mod, int range)
{
    vector<int> freqArr(range, 0), ans(arr.size());

    for(int i=0; i<arr.size(); i++)
        freqArr[(arr[i]/exp) % mod]++;

    for(int i=1; i<freqArr.size(); i++)
        freqArr[i] += freqArr[i-1];
    
    for(int i=0; i<freqArr.size(); i++)
        freqArr[i]--;

    for(int i=arr.size()-1; i>=0; i--)
    {                                   
        ans[ freqArr[(arr[i]/exp) % mod] ] = arr[i];
        freqArr[(arr[i]/exp) % mod]--;
    }
    
    for(int i=0; i<ans.size(); i++)
        arr[i] = ans[i];     
}


void sort01(vector<int> &arr)
{
    countSort(arr, 1000000, 100, 32);// days
    countSort(arr, 10000, 100, 13);// months
    countSort(arr, 1, 10000, 2501);// years
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    sort01(A);
    print(A);
    return 0;
}