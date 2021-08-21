#include<iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};
class linkedList
{
    node *head, *tail;

    public:

        linkedList()
        {
            head = nullptr;
            tail = nullptr;
        }
        //pass head a to traverse
        void traverse(node *nd)
        {
            if(nd == nullptr)
                return;

            traverse(nd->next);
            cout<<nd->val<<endl;
        }
};

int main()
{
    // node *nd1, *nd2, *nd3;

    node *nd1 = new node();
    node *nd2 = new node();
    node *nd3 = new node();
    nd1->val = 1;
    nd1->next = nd2;
    nd2->val = 2;
    nd2->next = nd3;  
    nd3->val = 3;
    nd3->next = nullptr;
    linkedList *list = new linkedList();
    list->traverse(nd1);
    
    delete nd1;
    delete nd2;
    delete nd3;
    delete list;
    return 0;
}
