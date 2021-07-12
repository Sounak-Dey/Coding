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
        
        LinkedList()       
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

        int showSize()
        {
            return size;
        }

        void display()
        {
            node *temp;
            temp = head;

            while(temp!= NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};



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
        else if(str.find("size") == 0)
            cout<<list.showSize()<<endl;

        else if(str.find("display") == 0)
            list.display();


        getline(cin, str);
    }

    return 0;
}

