#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    int size = A.size() + B.size();
    vector<int> merged(size);
    int i=0, j=0, k=0;

    while(i<A.size() && j<B.size())
    {
        if(A[i] <= B[j])
            merged[k++] = A[i++];

        else
            merged[k++] = B[j++];
    }

    if(i == A.size())
        while(j<B.size())
            merged[k++] = B[j++];

    else if(j == B.size())
        while(i<A.size())
            merged[k++] = A[i++];

    return merged;
}


void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
}

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    cin >> m;
    vector<int> B(m, 0);
    input(B);

    vector<int> ans = mergeTwoSortedArrays(A, B);
    output(ans);
    return 0;
}