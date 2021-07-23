#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int data, node *left, node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


void display(node *nd)
{
    if(nd == nullptr)
        return;


    string str = "";

    str += (nd->left == nullptr) ? "." : to_string(nd->left->data);
    str += " <- " + to_string(nd->data) + " -> ";
    str += (nd->right == nullptr) ? "." : to_string(nd->right->data);
    
    cout<<str<<endl;

    display(nd->left);
    display(nd->right);
}

node *construct(vector<int> &arr)
{
    node *root = new node(arr[0], nullptr, nullptr);
    
    stack<pair<node *, int>> st; 
    st.push({root, 1}); // st.top().second represents the state in which, the node represented by st.top().first is in
    int idx = 1;

    while(!st.empty())
    {
        if(st.top().second == 1) // state = 1 means visiting for adding left child
        {
            if(arr[idx] == NULL) // if left child is null
            {
                st.top().second++;  // st.top().first->left = nullptr; not needed as when we had created this node previously, we already set its both children as nullptr by default
            }
            else    // if left child exists
            {
                node *n = new node(arr[idx], nullptr, nullptr);
                st.top().first->left = n;
                st.top().second++;
                st.push({n, 1});
            }
            idx++;
        }
        else if(st.top().second == 2)   // state = 2 means visiting for ading right child
        {
            if(arr[idx] == NULL)
            {
               st.top().second++;
            }
            else
            {
                node *n = new node(arr[idx], nullptr, nullptr);
                st.top().first->right = n;
                st.top().second++;
                st.push({n, 1});
            }
            idx++;
        }
        else    // state = 3 means both children have been added, pop the stack top node
        {
            st.pop();
        }
    }
    
    return root;
}

int maxv(node *nd)
{
    if(nd->right == nullptr)
        return nd->data;

    return maxv(nd->right);
}


node *remove(node *nd, int data)
{
    if(nd->data == data)
    {
        if(nd->left == nullptr  &&  nd->right == nullptr) // if the node is a leaf node
            return nullptr;
        
        else if(nd->left != nullptr  &&  nd->right == nullptr)  // if only left child exists
            return nd->left;
        
        else if(nd->left == nullptr  &&  nd->right != nullptr) //if only right child exists
            return nd->right;
        
        else    // if both left and right child exists
        {
            node *nn = new node(0, nullptr, nullptr);   // create a new node and set it with max value of the left subtree
            
            nn->data = maxv(nd->left);  // set new nodes->data = max of left subtree
            nn->right = nd->right;          // set new nodes->right to point to the current nd->right
            nn->left = remove(nd->left, nn->data);  // remove the max of the left subtree(only left child will exist for the max node)

            return nn;      //replace the current node with this new node we created
        }
    }

    if(data < nd->data)
    {
        nd->left = remove(nd->left, data);
    }
    else if(data > nd->data)
    {
        nd->right = remove(nd->right, data);
    }

    return nd;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    string c;
    for(auto &x: arr)
    {
        cin>>c;
        if(isdigit(c[0]))
            x = stoi(c);
        else
            x = NULL;
    }

    int data;
    cin>>data;

   node *root = construct(arr);
   root = remove(root, data);
   display(root);

   return 0;
}
