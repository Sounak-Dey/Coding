#include <bits/stdc++.h>
using namespace std;


vector<int> shellto1d();
void rotate();
void onedtoshell();

int main()
{
    int n, m;
    int i, j;

    vector<vector<int>> a(n, vector<int> (m));

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin>>a[i][j];

    shellto1d();
    rotate();
    onedtoshell();
}