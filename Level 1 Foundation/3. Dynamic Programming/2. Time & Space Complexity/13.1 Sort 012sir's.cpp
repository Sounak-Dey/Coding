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
        cout << arr[i] << endl;

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

void sort012(vector<int> &arr)
{
    // 0 - j-1 ->  0's
    // j - i-1 ->  1's
    // k+1 - arr.size()-1 ->  2's
    // i - k -> unexlored

    int i = 0;
    int j = 0;
    int k = arr.size()-1;

    while(i <= k)
    {
        if(arr[i] == 2)
        {
            swap(arr, i, k);
            k--;        // didn't do i++ because we dont know what k'th index contained
        }
        else if(arr[i] == 0)
        {
            swap(arr, i, j);
            i++;
            j++;
        }
        else
            i++;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    sort012(A);
    print(A);
    return 0;
}