#include<iostream>
#include<vector>
#include<string>

using namespace std;

class twoStack
{

    public:

        // vector<int> data;
        int *data;
        int dsize;

        twoStack(int cap)
        {
            data = new int(cap);

            dsize = sizeof(data[0]) * cap;
            
            data[0] = 1;
            data[1] = 2;
            data[2] = 3;
            data[3] = 4;
            data[4] = 5;
            data[5] = 6;

        }

        void size()
        {
            cout<< data<<endl;
        }


};

int main()
{
    int n;
    cin>>n;
    twoStack st(n);
    st.size();

    return 0;
}