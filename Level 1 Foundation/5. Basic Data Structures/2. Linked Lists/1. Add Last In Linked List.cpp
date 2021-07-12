#include<iostream>
#include<vector>

using namespace std;

struct node
{
    int data;
    node *next;     
};

class LinkedList
{
    public:

        node *head, *tail;
        int size;
        
        LinkedList()        // this constructor definition is compulsory, else I get segmentation fault
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        void addLast(int val)
        {
            node *temp = new node();
            
            temp->data = val;
            temp->next = NULL;
            
            if(head == NULL)
                head = temp;
            else
                tail->next = temp;
                
            tail = temp;
            size++;
        }
};

void testList(LinkedList list)
{
    node *temp = new node();
    temp = list.head;

    while(temp!= NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<list.size<<endl;

    if(list.size > 0)
        cout<<list.tail->data;
}


int main()
{
    LinkedList list;

    string str;
    getline(cin,str);

    while(str.compare("quit") != 0)
    {
        if(str.find("addLast") == 0)
        {
            int val = stoi(str.substr(str.find(" ") + 1));
            list.addLast(val);
        }

        getline(cin, str);
    }

    testList(list);

    return 0;
}

