#include <bits/stdc++.h>
using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc)
{
    vector<string> h, v, d, a;

    if(sr==dr && sc==dc)
    {
        a.push_back("");
        return a;
    }
    else if(sc > dc)
        return a;
    else if(sr > dr)
        return a;


    for(auto js=1; js<=dc-sc; js++)
    {
        h = getMazePaths(sr, sc+js, dr, dc);
        for(auto x: h)
            a.push_back('h' + to_string(js) + x);
    }
    
    for(auto js=1; js<=dr-sr; js++)
    {
        v = getMazePaths(sr+js, sc, dr, dc);
        for(auto x: v)
            a.push_back('v' + to_string(js) + x);
    }
    
    for(auto js=1; (js<=dc-sc && js<=dr-sr); js++)
    {
        d = getMazePaths(sr+js, sc+js, dr, dc);
        for(auto x: d)
            a.push_back('d' + to_string(js) + x);
    }

    return a;

}


void display(vector<string>& arr)
{
    cout << "[";
    for(int i = 0;i < arr.size();i++)
    {
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() 
{
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}