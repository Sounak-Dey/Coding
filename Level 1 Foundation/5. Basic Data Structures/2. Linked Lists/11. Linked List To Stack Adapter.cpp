#include<iostream>
#include<string>
#include<list>

using namespace std;

class LTSA
{
    public:

        list<int> l;

        int size()
        {
            return l.size();
        }

        void push(int val)
        {
            l.push_back(val);
        }

        int pop()
        {
            if(size() == 0)
            {
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            else
            {
                int val = l.back();
                l.pop_back();
                return val;
            }
        }

        int top()
        {
            if(size() == 0)
            {
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            else
            {
                int val = l.back();
                return val;
            }
        }
};   


int main()
{
    LTSA st;
    string str;
    getline(cin, str);

    while(str.compare("quit") != 0)
    {
        if(str.find("push") == 0)
        {
            int val = stoi(str.substr(str.find(" ") + 1));
            st.push(val);
        }
        else if(str.find("pop") == 0)
        {
            int val = st.pop();
            if(val != -1)
                cout<<val<<endl;
        }
        else if(str.find("top") == 0)
        {
            int val = st.top();
            if(val != -1)
                cout<<val<<endl;
        }
        else if(str.find("size") == 0)
            cout<<st.size()<<endl;
        
        getline(cin, str);
    }

    return 0;
}