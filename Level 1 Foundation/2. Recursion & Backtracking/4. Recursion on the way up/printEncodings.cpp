#include <bits/stdc++.h>
using namespace std;

char codes[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void printEncoding(string str, string asf)
{
    if(str.length() == 0)
    {
        cout<<asf<<endl;
        return;
    }

    int d1 = str[0] - '0';

    if(d1 == 0)
        return;

    printEncoding(str.substr(1), asf + codes[d1-1]);


    if(str.length() > 1)
    {
        int d2 = str[1] - '0';
        int n = d1*10 + d2;

        if(n<=26)
            printEncoding(str.substr(2), asf + codes[n-1]);
    }
}


int main()
{
    string str;
    cin>>str;
    printEncoding(str,"");
    
    return 0;
}