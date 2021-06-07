#include <bits/stdc++.h>
using namespace std;

vector<string> gsp(int n)
{
    vector<string> v1, v2, v3, v;

    if(n==0)
    {
        v.push_back("");
        return v;
    }
    else if(n<0)
        return v;

    v1 = gsp(n-1);
    v2 = gsp(n-2);
    v3 = gsp(n-3);


    for(auto x: v1)
        v.push_back('1' + x);

    for(auto x: v2)
        v.push_back('2' + x);

    for(auto x: v3)
        v.push_back('3' + x);

    return v;
}


int main()
{
    int n;
    cin>>n;

    vector<string> ans = gsp(n);
    int cnt = 0;

    cout << '[';
    for (auto str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';

    return 0;
}