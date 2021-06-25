#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(vector<int> &arr)
{
    int pinc = 0;    // stores the max value till now if previous element is included
    int pexc = 0;    // stores the max value till now if previous element is excluded
    int inc, exc;   // current include, exclude

    for(int i=0; i<arr.size(); i++)
    {
        inc = pexc + arr[i];        // previous element was excluded
        exc = max(pinc, pexc);       // max of previous elements include and exclude

        pinc = inc;
        pexc = exc;
    }
    cout<<max(inc, exc);
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &x: arr)
        cin>>x;

    solve(arr);

    return 0;
}