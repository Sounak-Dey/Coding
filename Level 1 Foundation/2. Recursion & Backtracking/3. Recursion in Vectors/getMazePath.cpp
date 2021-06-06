#include <bits/stdc++.h>
using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc)
{
    vector<string> v1, v2, v3, v4, v;

    if(sr==dr && sc==dc)
    {
        v.push_back("");
        return v;
    }
    else if(sc > dc)
        return v;
    else if(sr > dr)
        return v;

    v1 = getMazePaths(sr, sc+1, dr, dc);
    v2 = getMazePaths(sr+1, sc, dr, dc);

    for(auto x: v1)
        v.push_back('h' + x);
    for(auto x: v2)
        v.push_back('v' + x);

    return v;

}


void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}