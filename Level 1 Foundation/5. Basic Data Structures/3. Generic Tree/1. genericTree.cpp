#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

//structure of a node of the tree
struct node
{
    int data;
    vector<node *> children; // children itself is an object of type vector(of type node*), so will use 'children.' operator
                             // but indivisual elements of children i.e children[i] are pointers ... & will use children[i]-> operator
};


//diplay the tree
void display(node *nd)
{
    string str = to_string(nd->data) + " -> ";  // display current node data

    for(auto child: nd->children)       
        str += to_string(child->data) + ", ";   // display all the children data

    str += ".";
    cout<<str<<endl;

    for(auto child: nd->children)   // recursive call... to each child node, to print its data and children data
        display(child);
}


//construct a tree from an array using Left to Right - Depth First Search
node *construct(vector<int> arr)
{
    node *root = nullptr;
    stack<node *> st;       // we will use the stack to implement the tree hierarchy, whenever a node arrives, its parent will be at the stack top() already

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == -1)    // when we see a '-1', it means that the node present at the top() (and its children) have been explored already ... so pop()
            st.pop();
        
        else        
        {
            node *t = new node();       // else create new node for the element
            t->data = arr[i];           

            if(st.empty())       // if stack is empty means this node doesnt have any parent... so make it as the root node  
                root = t;
            else
                st.top()->children.push_back(t);      // else if stack is not empty ... append the current node as a child to the node present at the stack top()         
                           
            
            st.push(t);     // at last the push the current node to the stack top top explore its children
        }
    }

    return root;
}




int main()
{
    vector<int> arr{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    node *root = construct(arr);
    display(root);

    return 0;
}