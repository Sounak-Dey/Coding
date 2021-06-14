#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


void crypt(string unique, int idx, unordered_map<char, int> &m, vector<bool> &usedNumbers, string s1, string s2, string s3)
{

    if(unique.length() > 10)
        return;

    
    if(idx == unique.length() )
    {
        int val1=0, val2=0, val3=0;

        for (int i = 0; i < s1.length(); i++)
        val1 = 10*val1 + m[s1[i]];

        for (int i = 0; i < s2.length(); i++)
        val2 = 10*val2 + m[s2[i]];

        for (int i = 0; i < s3.length(); i++)
        val3 = 10*val3 + m[s3[i]];

        if(val1 + val2 == val3)
        {
        for(auto i=0; i<26; i++)
        {
            char ch = (char)('a' + i);
            if(m.find(ch) != m.end())
            cout<<ch<<"-"<<m[ch]<<" ";
        } 
        cout<<endl;
        }
        return;
  }
  
  for(auto n=0; n<10; n++)
  {
    if(usedNumbers[n] != true)
    {
      usedNumbers[n] = true;
      m[unique[idx]] = n;
      crypt(unique, idx+1, m, usedNumbers, s1, s2, s3);
      usedNumbers[n] = false;
      m[unique[idx]] = -1 ; 
    }
  }
}

int main()
{
    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    unordered_map<char, int> m;

    string unique = "";

    for (int i = 0; i < s1.length(); i++) 
      if (m.find(s1[i]) == m.end()) 
      {
        m[s1[i]] = -1;
        unique += s1[i];
      }


    for (int i = 0; i < s2.length(); i++) 
      if (m.find(s2[i]) == m.end()) 
      {
        m[s2[i]] = -1;
        unique += s2[i];
      }

    for (int i = 0; i < s3.length(); i++) 
      if (m.find(s3[i]) == m.end()) 
      {
        m[s3[i]] = -1;
        unique += s3[i];
      }


    vector<bool> usedNumbers(10);

    crypt(unique, 0, m, usedNumbers, s1, s2, s3);

    return 0;
}
