#include<bits/stdc++.h>
using namespace std;

class MedianPriorityQueue
{
    public:

        priority_queue<int> left; // max heap
        priority_queue<int, vector<int>, greater<int>> right; //min heap

        void add(int val)
        {
            if(!right.empty()  &&  val > right.top())
                    right.push(val);
            else
                left.push(val);


            if(left.size() - right.size() == 2)
            {
                right.push(left.top());
                left.pop();
            }    
            else if(right.size() - left.size() == 2)
            {
                left.push(right.top());
                right.pop();
            }    
        }

        int remove()
        {
            if(this->size() == 0)
            {
                cout<<"Underflow"<<endl;
                return -1;
            }
            
            int top;
            if(left.size() >= right.size())
            {
                top = left.top();
                left.pop();
            }
            else
            {
                top = right.top();
                right.pop();
            } 

            return top;
        }

        int peek()
        {
            if(this->size() == 0)
            {
                cout<<"Underflow"<<endl;
                return -1;
            }

            if(left.size() >= right.size())
                return left.top();
            else 
                return right.top();
        }

        int size()
        {
            return left.size() + right.size();
        }
};

int main()
{
    MedianPriorityQueue mpq;
    string str;
    getline(cin, str);

    while(str.compare("quit") != 0)
    {
        if(str.find("add") == 0)
        {
            int val = stoi(str.substr(str.find(" ") + 1));
            mpq.add(val);
        }
        else if(str.find("remove") == 0)
        {
            int val = mpq.remove();
            if(val != -1)
                cout<<val<<endl;
        }
        else if(str.find("peek") == 0)
        {
            int val = mpq.peek();
            if(val != -1)
                cout<<val<<endl;
        }
        else if(str.find("size") == 0)
            cout<<mpq.size()<<endl;


        getline(cin, str);
    }

    return 0;
}