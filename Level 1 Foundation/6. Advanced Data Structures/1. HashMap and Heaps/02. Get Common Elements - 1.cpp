#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void solve(vector<int> &a1, vector<int> &a2)
{
    unordered_set<int> s1, s2;

    for(auto i: a1)
        s1.insert(i);
    
    for(auto i: a2)
    {
        if(s1.find(i) != s1.end())
        {
            cout<<i<<endl;
            s1.erase(i);
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