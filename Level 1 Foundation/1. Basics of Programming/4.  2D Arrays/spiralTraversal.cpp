#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    
    cin>>n>>m;

    vector<vector<int>> arr(n, vector<int> (m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>arr[i][j];

    int cnt = 0;
    int tne  = n * m;
    int minr = 0;
    int minc = 0;
    int maxr = n - 1;
    int maxc = m - 1;
      
    while(cnt < tne)
    {
        for(int i = minr; i <= maxr && cnt < tne; i++)
        {
            cout<<arr[i][minc]<<"\n";
            cnt++;
        }
        minc++;

        for(int j = minc; j <= maxc && cnt < tne; j++)
        {
            cout<<(arr[maxr][j])<<"\n";
            cnt++;
        }
        maxr--;

        for(int i = maxr; i >= minr && cnt < tne; i--)
        {
            cout<<(arr[i][maxc])<<"\n";
            cnt++;
        }
        maxc--;

        for(int j = maxc; j >= minc && cnt < tne; j--)
        {
            cout<<(arr[minr][j])<<"\n";
            cnt++;
        }
        minr++;

    }

    return 0;
   

}