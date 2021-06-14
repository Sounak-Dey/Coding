#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    map<char, int> m;

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


    cout<< unique<<endl;
    for(auto x: m)
      cout<<x.first<<" "<<x.second<<endl;
}