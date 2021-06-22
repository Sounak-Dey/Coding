#include<iostream>
#include<string>
#include<map>

using namespace std;

//ssf - spots so far
//ts - total spots
void combination(map<char, int> &fmap, int i, string ustr, int ssf, int ts, string asf)
{
    if(i == ustr.length())
        return;
    
    if(ssf == ts)
    {
        cout<<asf<<endl;
        return;
    }

    int f = fmap[ustr[i]];
    int pssf = ssf;
    string pasf = asf;
    // every character gets an option to be included or not included
    
    //include
    while(fmap[ustr[i]]>0)
    {
        fmap[ustr[i]]--;
        asf += ustr[i];
        ssf++;
        if(ssf == ts)
            break;
    }
    combination(fmap, i+1, ustr, ssf, ts, asf);
    fmap[ustr[i]] = f;
    asf = pasf;
    ssf = pssf;
    
    //not include
    combination(fmap, i+1, ustr, ssf, ts, asf);
}



int main()
{
    string str;
    getline(cin, str);

    int k;
    cin>>k;

    map<char, int> fmap;
    string ustr;

    for(auto &ch: str)
    {
        if(fmap.find(ch) == fmap.end())
            ustr += ch;
            
        fmap[ch]++;
    }
        
    for(auto ch: fmap)
        cout<<ch.first<<" "<<ch.second<<endl;


    // combination(fmap, 0, str, 0, k, "");
    return 0;
}