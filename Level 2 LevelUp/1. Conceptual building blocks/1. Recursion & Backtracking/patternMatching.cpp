#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

void solution(string str, string rp, unordered_map<char, string> &hmap, string op, string &pattern, string &ostr)
{
    if(str.size() == 0 || rp.size() == 0)
    {
        string result = "";
        for(int i=0; i<pattern.length(); i++)   //generating string from hmap
        {
            char ch = pattern[i];
            result += hmap[ch];
        }
        if(ostr.compare(result) == 0)       //comparing generated string and original string
            cout<<op<<"."<<endl;
        
        return;
    }

    char k = rp[0];
    auto i = hmap.find(k);

    for(int l=1; l<=str.size(); l++)
    {
        string s = str.substr(0, l);
    
        if(i != hmap.end())     // if pattern mapping is already present
        {    
            if(hmap[k].compare(s) == 0)
                solution(str.substr(l), rp.substr(1), hmap, op, pattern, ostr);
        }
        else                    // if pattern mapping not present
        {
            hmap[k] = s;
            solution(str.substr(l), rp.substr(1), hmap, op + k + " -> " + s + ", ", pattern, ostr);
            hmap.erase(k);
        }
    }
    return;
}

int main()
{
    string str, pattern;
    cin>>str>>pattern;

    unordered_map<char, string> hmap;
    
    solution(str, pattern, hmap, "", pattern, str);

    return 0;
}