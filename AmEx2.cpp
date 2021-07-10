#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdint>

using namespace std;

long double  eucD(long long int q1, long long int p1, long long int q2, long long int p2)
{
    long double ed ;

    long long sum = pow(q1 - p1, 2) + pow(q2 - p2, 2);

    ed = sqrt(sum);

    return ed;
}


int main()
{
    int n;
    cin>> n;

    vector<vector<long long int>> bcdata(n, vector<long long int> (3));

    for(long long int i=0; i<n; i++)
    {
        cin>>bcdata[i][0];
        cin>>bcdata[i][1];
        cin>>bcdata[i][2];
    }


    int m;
    cin>>m;

    vector<vector<long long int>> cudata(m, vector<long long int> (3));

    for(long long int i=0; i<n; i++)
    {
        cin>>cudata[i][0];
        cin>>cudata[i][1];
        cin>>cudata[i][2];
    }


    vector<long long int> ans;

    for(int i=0; i<m; i++)
    {
        
        if(cudata[i][1]>0  &&  cudata[i][2]>0)
        {
            long double d = INT64_MAX, ed;
            long long int  nn;
            for(int j=0; j<n; j++)// finding the nearest neighbour
            {
                ed = eucD(cudata[i][1], bcdata[j][1], cudata[i][2], bcdata[j][2]);
                
                if(ed<d)
                {
                    d = ed;
                    nn = j; // storing the nearest neighbour
                }
            }

            long double D = INT64_MAX;
            long long int nnn;
            for(int j=0; j<n; j++)// finding the nearest neighbour of nn
            {
                if(j != nn)
                {
                    ed = eucD(bcdata[nn][1], bcdata[j][1], bcdata[nn][2], bcdata[j][2]);
                
                    if(ed<D)
                    {
                        D = ed;
                        nnn = j; // storing the nearest neighbour of nn
                    }
                }
                
            }

            if(d/D < 1)
            {
                ans.push_back(cudata[i][0]);
            }
        }
    }

    sort(ans.begin(), ans.end());

    for(auto x: ans)
        cout<<x<<endl;

    return 0;
}