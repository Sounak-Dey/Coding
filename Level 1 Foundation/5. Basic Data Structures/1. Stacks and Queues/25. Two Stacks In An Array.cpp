#include<iostream>
#include<vector>
#include<string>

using namespace std;

class twoStack
{

    public:

        int *data = new int(5);
        int tos1;
        int tos2;
        int max;

        twoStack(int cap)
        {
            // data = new int(5);
            tos1 = -1;
            tos2 = cap;
            max = cap;
        }

        int size1()
        {
            return tos1 + 1;

        }

        int size2()
        {
            return max - tos2;
        }

        void push1(int val)
        {
            if(tos2 == tos1 + 1)
                cout<<"Stack overflow"<<endl;
            else
            {
                tos1++;
                data[tos1] = val;
            }
                
        }

        void push2(int val)
        {
            if(tos2 == tos1 + 1)
                cout<<"Stack overflow"<<endl;
            else
            {
                tos2--;
                data[tos2] = val;
            }
                
        }

        int pop1()
        {
            if(tos1 == -1)
            {
                cout<<"Stack overflow"<<endl;
                return -1;
            }
            else
                return data[tos1--];
                
        }

        int pop2()
        {
            if(tos2 == max)
            {
                cout<<"Stack overflow"<<endl;
                return -1;
            }
            else
               return data[tos2++];
        }

        int top1()
        {
            if(tos1 == -1)
            {
                cout<<"Stack overflow"<<endl;
                return -1;
            }
            else
                return data[tos1];
        }

        int top2()
        {
            if(tos2 == max)
            {
                cout<<"Stack overflow"<<endl;
                return -1;
            }
            else
               return data[tos2];
        }

};

int main()
{
    int n;
    twoStack st(n);
    string str;
    getline(cin, str);
    
    while(str.compare("quit") != 0)
    {
        if(str.find("push1") == 0) // checking what the instruction starts with
        {
            int val = stoi(str.substr(str.find(" ")+1)); // checking the value next to push1
            st.push1(val);
        }
        if(str.find("pop1") == 0)
        {
            int val = st.pop1();
            if(val != -1)
                cout<<val<<endl;
        }
        else if(str.find("top1") == 0) 
        {
            int val = st.top1();
            if (val != -1) 
                cout<<(val)<<endl;
        }
        else if(str.find("size1") == 0) 
            cout<<(st.size1())<<endl;

        else if(str.find("push2") == 0)
        {
            int val = stoi(str.substr(str.find(" ")+1));
            st.push1(val);
        }
        else if(str.find("pop2") == 0)
        {
            int val = st.pop1();
            if(val != -1)
                cout<<val<<endl;
        }
        else if(str.find("top2") == 0) 
        {
            int val = st.top1();
            if (val != -1) 
                cout<<(val)<<endl;
        }

        else if(str.find("size2") == 0) 
            cout<<(st.size1())<<endl;
        
        getline(cin, str);
    }

    return 0;
}