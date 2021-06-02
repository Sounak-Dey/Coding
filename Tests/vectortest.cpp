#include<bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int> a, vector<vector<int>> b)
{
    cout<< b.size()<<endl;
    cout<< b[0].size()<<endl; 

    vector<int> v(a.size());

    for(int i=0; i<a.size(); i++)
        v[i]=a[i];

    return v;

}

int main()
{
    int n,r,c;
    cin>>n;

    vector<int> a(n);

    for(int i=0; i<n; i++)
        cin>>a[i];
    
    cin>>r>>c;
    vector<vector<int>> b(r, vector<int> (c));

    vector<int> v = fun(a,b);

    for(int i=0; i<n; i++)
        cout<<"copy"<<v[i]<<endl;

    return 0;
}