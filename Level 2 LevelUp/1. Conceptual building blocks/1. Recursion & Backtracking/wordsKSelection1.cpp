#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

//ssf - spots so far
//ts - total spots
void combination(int i, string ustr, int ssf, int ts, string asf)
{
    if(i == ustr.length())
        return;
    
    if(ssf == ts)
    {
        cout<<asf<<endl;
        return;
    }

    //include
    combination(i+1, ustr, ssf+1, ts, asf + ustr[i]);

    //not include
    combination(i+1, ustr, ssf, ts, asf);
}



int main()
{
    string str;
    getline(cin, str);

    int k;
    cin>>k;

    unordered_set<char> unique;
    string ustr = "";

    for(auto ch: str)
        if(unique.find(ch) == unique.end())
        {
            unique.insert(ch);
            ustr += ch;
        }

    combination(0, ustr, 0, k, "");
    return 0;
}