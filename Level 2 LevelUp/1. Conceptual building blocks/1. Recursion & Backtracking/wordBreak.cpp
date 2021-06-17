#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

void wordBreak(string sentence, string ans, unordered_set<string> dict)
{
    if(sentence.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }

    
    for(int l=1; l<=sentence.size(); l++)       //checking for all possible prefixes
    {
        string word = sentence.substr(0, l);

        if(dict.find(word) != dict.end())       // word found in dict
        {
            wordBreak(sentence.substr(l), ans + word + " ", dict);
        }
    }
}

int main()
{
    int n;
    cin>>n;

    unordered_set<string> dict(n);
    string x, sentence;
    
    for(int i=0; i<n; i++)
    {
        cin>>x;
        dict.insert(x);
    } 
    cin>>sentence;

    wordBreak(sentence, "", dict);
    return 0;
}