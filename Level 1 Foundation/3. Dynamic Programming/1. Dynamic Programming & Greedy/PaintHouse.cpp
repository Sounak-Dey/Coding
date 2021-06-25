#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(vector<vector<int>> &rbg)
{
    int pr = rbg[0][0]; //stores minimum painting cost if previous house had been painted red
    int pb = rbg[0][1];
    int pg = rbg[0][2];
    int r, g, b;        //stores minimum painting cost if current house is painted red, blue or green
    
    int i=1;
    while( i < rbg.size())
    {
        r = min(pb, pg) + rbg[i][0];    //min cost if prev was not painted red + cost to paint current red
        b = min(pr, pg) + rbg[i][1];
        g = min(pr, pb) + rbg[i][2];

        i++;
        pr = r;
        pb = b;
        pg = g;
    }
    cout<<min({r, b, g});
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> rbg(n, vector<int> (3));

    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            cin>>rbg[i][j];
    
    solve(rbg);
    return 0;
}