#include<bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    private:

        vector<int> data;

        void swap(int idx1, int idx2)
        {
            int temp = data[idx1];
            data[idx1] = data[idx2];
            data[idx2] = temp;
        }

        void upheapify(int idx)
        {
            if(idx == 0)
                return;

            int parent = (idx-1)/2;
            if(data[idx] < data[parent])
            {
                swap(idx, parent);
                upheapify(parent);
            }
        }

        void downheapify(int idx)
        {
            int minidx = idx;

            int left = 2*idx + 1;
            int right = 2*idx + 2;

            if(left<data.size()  &&  data[left] < data[minidx])
                minidx = left;
            
            if(right<data.size()  &&  data[right] < data[minidx])
                minidx = right;
            
            if(minidx != idx)
            {
                swap(idx, minidx);
                downheapify(minidx);
            }
        }


    public:
    
        void add(int val)
        {
            data.push_back(val);
            upheapify(data.size()-1);
        }

        int remove()
        {
            int val = this->peek();
            if(val == -1)
                return val;
            
            this->swap(0, data.size()-1);
            data.pop_back();
            downheapify(0);

            return val;
        }

        int peek()
        {
            if(this->size() == 0)
            {
                cout<<"Underflow"<<endl;
                return -1;
            }  

            return data[0];
        }

        int size()
        {
            return data.size();
        }
};



int main()
{
    PriorityQueue pq;
    string str;
    getline(cin, str);

    while(str.compare("quit") != 0)
    {
        if(str.find("add") == 0)
        {
            int val = stoi(str.substr(str.find(" ") + 1));
            pq.add(val);
        }
        else if(str.find("remove") == 0)
        {
            int val = pq.remove();
            if(val != -1)
                cout<<val<<endl;
        }
        else if(str.find("peek") == 0)
        {
            int val = pq.peek();
            if(val != -1)
                cout<<val<<endl;
        }
        else if(str.find("size") == 0)
            cout<<pq.size()<<endl;


        getline(cin, str);
    }

    return 0;
}