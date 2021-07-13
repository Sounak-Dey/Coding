#include<iostream>
#include<string>
#include<list>

using namespace std;

class LTQA
{
    public:

        list<int> l;

        int size()
        {
            return l.size();
        }

        void add(int val)
        {
            l.push_back(val);
        }

        int remove()
        {
            if(size() == 0)
            {
                cout<<"Queue underflow"<<endl;
                return -1;
            }
            else
            {
                int val = l.front();
                l.pop_front();
                return val;
            }
        }

        int peek()
        {
            if(size() == 0)
            {
                cout<<"Queue underflow"<<endl;
                return -1;
            }
            else
            {
                int val = l.front();
                return val;
            }
        }
};   


int main()
{
    LTQA q;
    string str;
    getline(cin, str);

    while(str.compare("quit") != 0)
    {
        if(str.find("add") == 0)
        {
            int val = stoi(str.substr(str.find(" ") + 1));
            q.add(val);
        }
        else if(str.find("remove") == 0)
        {
            int val = q.remove();
            if(val != -1)
                cout<<val<<endl;
        }
        else if(str.find("peek") == 0)
        {
            int val = q.peek();
            if(val != -1)
                cout<<val<<endl;
        }
        else if(str.find("size") == 0)
            cout<<q.size()<<endl;
        
        getline(cin, str);
    }

    return 0;
}