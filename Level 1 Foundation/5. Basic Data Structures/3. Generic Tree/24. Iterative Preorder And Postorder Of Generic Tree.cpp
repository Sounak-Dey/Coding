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

vector<int> pre, post;
// void iterativePrePost(node *root)
// {
//     stack<pair<node*, int>> st;
//     // vector<int> pre, post;
//     st.push({root, -1});

//     while(!st.empty())
//     {
//         if(st.top().second == -1)
//         {
//             pre.push_back(st.top().first->data);
//             st.top().second++;
//             st.push({st.top().first->children[st.top().second], -1}); // this push will go out of bounds for leaf, as it will try to
//         }                                                           // push leaf->children[0] which doesn't exist
//         else if(st.top().second < st.top().first->children.size())
//         {
//             st.top().second++;
//             st.push({st.top().first->children[st.top().second], -1});
//         }
//         else if(st.top().second == st.top().first->children.size())
//         {
//             post.push_back(st.top().first->data);
//             st.pop();
//         }
//     }
// }

void iterativePrePost(node *root)
{
    stack<pair<node*, int>> st;
    st.push({root, -1});

    while(!st.empty())
    {
        if(st.top().second == -1) //preorder visit
        {
            pre.push_back(st.top().first->data);
            st.top().second++;
        }
        else if(st.top().second < st.top().first->children.size())
        {
            int idx = st.top().second;
            st.top().second++;                              //increase the state of the top before pushing the child
            st.push({st.top().first->children[idx], -1});
        }
        else if(st.top().second == st.top().first->children.size()) //postorder visit
        {
            post.push_back(st.top().first->data);
            st.pop();
        }
    }
}



int main()
{
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    for(auto &i: arr1)
        cin>>i;

    node *root = construct(arr1);
    
    iterativePrePost(root);

    for(auto x: pre)
        cout<<x<<" ";
    cout<<endl;

    for(auto x: post)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}