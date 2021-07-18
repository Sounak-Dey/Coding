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

    else if(nd->data > data)
        ceil = min(ceil, nd->data);
    
    else if(nd->data == data)
        ceil = floor = data;
        

    for(auto child: nd->children)
        cf(child, data);
}


int main()
{
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    for(auto &i: arr1)
        cin>>i;

    int data;
    cin>>data;

    node *root = construct(arr1);
    ceil = INT32_MAX;
    floor = INT32_MIN;
    cf(root, data);

    cout<<"CEIL = "<<ceil<<endl;
    cout<<"FLOOR = "<<floor;

    return 0;
}