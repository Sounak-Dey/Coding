#include <iostream>
#include <map>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    map<string,int> m;
    int q, type, y;
    string x;
    
    cin>>q;
    while(q--)
    {   
        cin>>type>>x;
        
        // map<string, int> :: iterator i;
        auto i = m.find(x);
        
        switch(type)
        {
            case 1: 
                cin>>y;
                if(i != m.end())
                {
                    i->second += y;
                }
                else
                    // m.insert(make_pair(x,y));
                    m.insert({x, y});
                break;
            case 2:
                if(i != m.end())
                {
                    m.erase(x);
                }
                break;
            case 3:
                if(i != m.end())
                {
                    cout<<i->second<<endl;
                }   
                else
                    cout<<0<<endl;
                break;
        }
        
    }
    
      
    return 0;
}



