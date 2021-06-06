#include <bits/stdc++.h>
using namespace std;

vector<string> gss(string s)
{
    vector<string> v, r;

    if(s.length() == 0)
    {
        r.push_back("");
        return r;
    }
    
    v = gss(s.substr(1));

    for(auto x:v)
        r.push_back("" + x);
    for(auto x:v)
        r.push_back(s[0] + x);
    
    return r;
}


int main()
{
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';

    return 0;
}