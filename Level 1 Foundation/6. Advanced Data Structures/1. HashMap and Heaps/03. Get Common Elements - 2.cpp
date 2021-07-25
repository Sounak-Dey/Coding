#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void solve(vector<int> &a1, vector<int> &a2)
{
    unordered_map<int, int> fmap;

    for(auto i: a1)
        fmap[i]++;
    
    for(auto i: a2)
    {
        if(fmap.find(i) != fmap.end()  &&  fmap[i] > 0)
        {
            fmap[i]--;
            cout<<i<<endl;
        }
    }
}

int main()
{
    int n1;
    cin>>n1;

    vector<int> a1(n1);
    for(auto &x: a1)
        cin>>x;

    int n2;
    cin>>n2;

    vector<int> a2(n2);
    for(auto &x: a2)
        cin>>x;

    solve(a1, a2);

    return 0;
}