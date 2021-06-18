#include<iostream>
#include<vector>

using namespace std;

void combinations1(string &boxes,int bi, int r)
{
    if(bi== boxes.length())
    {
        if(r == 0)
            cout<<boxes<<endl;
        
        return;
    }

    //every box has an option to include or not include 'i'

    //include
    boxes[bi] = 'i';
    combinations1(boxes, bi+1, r-1);
    boxes[bi] = '-';

    //not include
    combinations1(boxes, bi+1, r);    
}


int main()
{
    int n, r;
    cin>>n>>r;
    
    string boxes(n, '-');

    combinations1(boxes, 0, r);

    return 0;
}