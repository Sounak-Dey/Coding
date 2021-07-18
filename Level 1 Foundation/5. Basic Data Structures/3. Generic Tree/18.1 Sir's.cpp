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

int lcaf(node *nd, int d1, int d2)
{
    vector<int> path1 = nodeToRootPath(nd, d1);
    vector<int> path2 = nodeToRootPath(nd, d2);

    int i = path1.size()-1;
    int j = path2.size()-1;

    while(i>=0 && j>=0  &&  path1[i] == path2[j]) 
    {
        i--;
        j--;
    }

    return path1[i+1];
}

bool areSimilar(node *n1, node *n2)   // for two trees two be similar, check if the current node's number of children are same
{                                     // if yes, recursively check for all its children are similar or not
    if(n1->children.size() == n2->children.size())
    {
        for(int i=0; i<n1->children.size(); i++)
        {
            node *child1 = n1->children[i];
            node *child2 = n2->children[i];

            bool flag = areSimilar(child1, child2);
            if(flag == false)
                return false;
        }

        return true;
    }

    return false;
}

bool mirror(node *n1, node *n2)
{                     
    if(n1->children.size() == n2->children.size())
    {
        int s1 = n1->children.size();
        int s2 = n2->children.size();
        for(int i=0, j=s2-1;  i<s1, j>=0;  i++, j--)
        {
            node *child1 = n1->children[i];     // traverse n1 from left
            node *child2 = n2->children[j];     // n2 from right

            bool flag = mirror(child1, child2);
            if(flag == false)
                return false;
        }

        return true;
    }

    return false;
}

bool symmetric(node *nd)
{
    return mirror(nd, nd); //  a symmetric tree shoud be the mirror image of itself
}                          // this covers every case

int main()
{
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    for(auto &i: arr1)
        cin>>i;

    node *root1 = construct(arr1);
    
    bool sym = symmetric(root1);
    if(sym == true)
        cout<<"true";
    else
        cout<<"false";

    return 0;
}