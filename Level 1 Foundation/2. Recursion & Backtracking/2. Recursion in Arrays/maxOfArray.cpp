#include <iostream>
using namespace std;

int max(int arr[], int idx, int n){
    
    int static m = arr[0];

    if(idx<n)
    {
        if(m<arr[idx])
            m = arr[idx];
        
        return max(arr, idx+1, n);
    }
    else
        return m;
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}
