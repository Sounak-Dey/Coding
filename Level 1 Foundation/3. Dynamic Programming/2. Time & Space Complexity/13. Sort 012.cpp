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
    // 0 - k-1 ->  0's
    // k - j-1 ->  1's
    // j - i-1 ->  2's
    // i - rest -> unexplored

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < arr.size())
    {
        if(arr[i] == 0)
        {
            swap(arr, i, k);    //swaps 0 1
            swap(arr, i, j);    // swaps 1 2
            i++;
            j++;
            k++;
        }
        else if(arr[i] == 1)
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