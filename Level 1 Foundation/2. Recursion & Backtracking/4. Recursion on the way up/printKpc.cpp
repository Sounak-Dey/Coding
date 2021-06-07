#include <bits/stdc++.h>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf)
{
    if(ques.length() == 0)
    {
        cout<<asf<<endl;
        return;
    }    

    int n = ques[0] - '0';
    string k = codes[n];

    for(int i=0; i<k.length(); i++)
    {
        printKPC(ques.substr(1), asf + k[i]);
    }
}

int main()
{
    string str;
    cin >> str;
    printKPC(str, "");
    return 0;
}