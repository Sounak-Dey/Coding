#include<iostream>
#include<unordered_set>

using namespace std;

// levels - spots
//options - characters
// levels < options
// so spots/levels dont have a choice of going blank
void solution(string &ustr, int k, string asf)
{
    
    if(k == 0)
    {
        cout<<asf<<endl;
        return;
    }
    // if(ustr.length() == 0)  // not needed as k will reach 0 first everytime
    //     return;

    for(int i=0; i<ustr.length(); i++)
    {
        char ch = ustr[i];
        ustr.erase(i, 1);
        solution(ustr, k-1, asf + ch); // don't do k-- , always do k-1
        ustr.insert(i, 1, ch);
    }
}


int main()
{
    string str, ustr = "";
    cin>>str;
    int k;
    cin>>k;

    unordered_set<char> unique;
    for(auto ch: str)
        if(unique.find(ch) == unique.end())
        {
            unique.insert(ch);
            ustr += ch;
        }
    
    solution(ustr, k, "");
    return 0;
}