#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

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

int size(node *nd)
{
    // if(nd == nullptr)    //not needed
    //     return 0;        

    int count = 0;
    for(auto child: nd->children)
        count += size(child);

    return count + 1;
}

int maxv(node *nd)
{
    int m = nd->data;
    for(auto child: nd->children)
        m = max(m, maxv(child));

    return m;
}

int height(node *nd)
{
    int h = 0;
    for(auto child: nd->children)
        h = max(h, height(child) + 1); // since height is calculated using edges, & edge exists only if child exists

    return h;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr)
        cin>>i;
    
    node *root = construct(arr);
    int h = height(root);
    cout<<h<<endl;
    // display(root);

    return 0;
}