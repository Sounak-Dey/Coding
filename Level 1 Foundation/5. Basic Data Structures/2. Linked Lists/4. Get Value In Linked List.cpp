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

        int getFirst()
        {
            if(head == NULL)
            {
                cout<<"List is empty"<<endl;
                return -1;
            }
            else
                return head->data;
        }

        int getLast()
        {
            if(tail == NULL)
            {
                cout<<"List is empty"<<endl;
                return -1;  
            }
            else
                return
                tail->data;
        }
        
       int getAt(int idx)
        {
            if(idx < 0 || idx >= size)
            {
                cout<<"Invalid arguments"<<endl;
                return -1;
            }
            // else if(head == NULL)        // not needed as, when head = NULL, size = 0, so if idx >=0 then it will return invalid arguments
            // {
            //     cout<<"List is empty"<<endl;
            //     return -1;
            // }
            else
            {
                node *temp = head;

                while(idx > 0)
                {
                    temp = temp->next;
                    idx--;
                }

                return temp->data;
            }
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

        void removeFirst()
        {
            if(head == NULL)
                cout<<"List is empty"<<endl;
                
            else if(head == tail)
            {
                head = NULL;
                tail = NULL;
                size--;
            }
            else
            {
                head = head->next;
                size--;    
            }
            
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
            
        else if(str.find("removeFirst") == 0)
            list.removeFirst();

        else if(str.find("getFirst") == 0)
        {
            int val = list.getFirst();
            if(val != -1)
                cout<<val<<endl;
        }

        else if(str.find("getLast") == 0)
        {
            int val = list.getLast();
            if(val != -1)
                cout<<val<<endl;
        }

        else if(str.find("getAt") == 0)
        {
            int idx = stoi(str.substr(str.find(" ") + 1));
            int val = list.getAt(idx);
            if(val != -1)
                cout<<val<<endl;
        }

        getline(cin, str);
    }

    return 0;
}