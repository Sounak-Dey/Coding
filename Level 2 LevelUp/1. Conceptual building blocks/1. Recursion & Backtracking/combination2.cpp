#include<iostream>
#include<vector>

using namespace std;

void combinations2(string &boxes,int bi, int r)
{
    if(r == 0)
    {
        cout<<boxes<<endl;
        return;
    }
    
    // if(bi == boxes.size())           need not be checked becoz it is taken
        // return                       care of by the for loop only
  
    //level - item
    //option - boxes

    for(int i=bi; i<boxes.size(); i++)
    {
        boxes[i] = 'i';
        combinations2(boxes, i+1, r-1);
        boxes[i] = '-';
    }
}


int main()
{
    int n, r;
    cin>>n>>r;
    
    string boxes(n, '-');

    combinations2(boxes, 0, r);

    return 0;
}