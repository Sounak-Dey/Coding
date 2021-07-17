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

bool findv(node *nd, int data)
{
    if(nd->data == data)
        return true;

    for(auto child: nd->children)
    {
        bool flag = findv(child, data); 
        if(flag == true)    // if any one child returns true, stop execution and return true
            return true;
    }    
    
    return false;
}

vector<int> nodeToRootPath(node *nd, int data)
{
    vector<int> path;
    
    if(nd->data == data)
    {
        path.push_back(nd->data);
        return path;
    }

    for(auto child: nd->children)
    {
        path = nodeToRootPath(child, data);
        if(path.size() > 0)
        {
            path.push_back(nd->data);
            return path;
        }
    }

    return path;
}

void display(vector<int>& arr)
{
    cout << "[";
    for(int i=0; i < arr.size(); i++)
    {
        cout << arr[i];
        if(i < arr.size() -1) 
            cout << ", ";
    }
    
    cout << "]"<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr)
        cin>>i;

    int data;
    cin>>data;

    node *root = construct(arr);
    vector<int> path = nodeToRootPath(root, data);
    display(path);

    return 0;
}