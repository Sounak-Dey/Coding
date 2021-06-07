#include <bits/stdc++.h>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf) 
{
    if(sr==dr && sc==dc)
    {
        cout<<psf<<endl;
        return;
    }
    else if(sr>dr || sc>dc)
        return;
    
    for(auto js=1; js<=dc-sc; js++)
        printMazePaths(sr, sc+js, dr, dc, psf + 'h' + to_string(js));
    for(auto js=1; js<=dr-sr; js++)
        printMazePaths(sr+js, sc, dr, dc, psf + 'v' + to_string(js));
    for(auto js=1; js<=dc-sc && js<=dr-sr; js++)
        printMazePaths(sr+js, sc+js, dr, dc, psf + 'd' + to_string(js));
}


int main() 
{
    int n ;
    int m ;cin>>n>>m;
    printMazePaths(0, 0, n - 1, m - 1, "");

    return 0;
}