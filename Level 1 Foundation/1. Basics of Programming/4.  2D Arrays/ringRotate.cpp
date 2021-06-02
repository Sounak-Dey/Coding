#include <bits/stdc++.h>
using namespace std;


vector<int> shellto1d(vector<vector<int>> a, int s)
{
    int minr = s-1;
    int minc = s-1;
    int maxr = a.size() - s;
    int maxc = a[0].size() - s;
    int size = 2*(maxr-minr + maxc-minc);

    vector<int> oned(size);
    int idx = 0;
    for(int i = minr, j=minc; i<= maxr; i++)
    {
        oned[idx] = a[i][j];
        idx++;
    }
    for(int i = maxr, j=minc+1; j<= maxc; j++)
    {
        oned[idx] = a[i][j];
        idx++;
    }
    for(int i = maxr-1, j=maxc; i >= minr; i--)
    {
        oned[idx] = a[i][j];
        idx++;
    }
    for(int i = minr, j=maxc-1; j >= minc+1; j--)
    {
        oned[idx] = a[i][j];
        idx++;
    }

    return oned;

}


void reverse(vector<int> &arr, int left, int right)
{
    
    while(left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}


void rotate(vector<int> &arr, int k)
{
    k = k % arr.size();
    if(k < 0)
    {
        k += arr.size();
    }
    reverse(arr,0,arr.size() - 1);
    reverse(arr,0 , k - 1);
    reverse(arr,k ,arr.size() - 1);
    
}


void onedtoshell(vector<vector<int>> &a, int s, vector<int> oned)
{
    int minr = s-1;
    int minc = s-1;
    int maxr = a.size() - s;
    int maxc = a[0].size() - s;

    int idx = 0;
    for(int i = minr, j=minc; i<= maxr; i++)
    {
        a[i][j] = oned[idx] ;
        idx++;
    }
    for(int i = maxr, j=minc+1; j<= maxc; j++)
    {
        a[i][j] = oned[idx] ;
        idx++;
    }
    for(int i = maxr-1, j=maxc; i >= minr; i--)
    {
        a[i][j] = oned[idx] ;
        idx++;
    }
    for(int i = minr, j=maxc-1; j >= minc+1; j--)
    {
        a[i][j] = oned[idx] ;
        idx++;
    }
}


int main()
{
    int n, m, s, r;
    int i, j;

    vector<vector<int>> a(n, vector<int> (m));

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin>>a[i][j];
    
    cin>>s>>r;

    vector<int> oned = shellto1d(a,s);
    rotate(oned, r);
    onedtoshell(a, s, oned);
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
        

    return 0;
}