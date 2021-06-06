#include <bits/stdc++.h>
using namespace std;

void printSS(string ques, string ans)
{
    if(ques.length() == 0)
    {
        // printf("%s",ans);
        cout<<ans<<endl;
        return;
    }    
    
    printSS(ques.substr(1), ans + ques[0]);
    printSS(ques.substr(1), ans + "");
}

int main()
{
    string str;
    cin >> str;
    printSS(str, "");

    return 0;
}