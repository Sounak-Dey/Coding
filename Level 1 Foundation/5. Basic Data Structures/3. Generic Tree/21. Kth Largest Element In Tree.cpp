#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

//structure of a node of the tree
struct node
{
    int data;
    vector<node *> children; 
                             
};


//diplay the tree
void display(node *nd)
{
    string str = to_string(nd->data) + " -> ";  

    for(auto child: nd->children)       
        str += to_string(child->data) + ", ";  

    str += ".";
    cout<<str<<endl;

    for(auto child: nd->children)   
        display(child);
}


//construct a tree from an array using Left to Right - Depth First Search
node *construct(vector<int> arr)
{
    node *root = nullptr;
    stack<node *> st;       

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == -1)    
            st.pop();
        
        else        
        {
            node *t = new node();       
            t->data = arr[i];           

            if(st.empty())      
                root = t;
            else
                st.top()->children.push_back(t);                         
            
            st.push(t);     
        }
    }

    return root;
}

int ceil;
int floor;

void cf(node *nd, int data)
{
    if(nd->data < data)
        floor = max(floor, nd->data);

    for(auto child: nd->children)
        cf(child, data);
}


int kthLargest(node *nd, int k)
{
    int factor = INT32_MAX;

    for(int i=0; i<k; i++) // runs k times to get the kth largest value
    {
        floor = INT32_MIN; // set floor = INT_MIN before every call, else cf(nd, floor) will be called everytime, as factor = floor after every iteration
        cf(nd, factor); // this will set floor = the largest value smaller than factor
        factor = floor;
    }
        
    return factor;
}


int main()
{
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    for(auto &i: arr1)
        cin>>i;

    int k;
    cin>>k;

    node *root = construct(arr1);
    cout<<kthLargest(root, k)<<endl;

    return 0;
}