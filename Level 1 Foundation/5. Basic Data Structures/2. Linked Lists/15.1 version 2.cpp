#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct node
{
    int data;
    node *next;     
};

class LinkedList
{
    private:

        node *getNodeAt(int idx)
        {
            node *temp = head;

            while(idx > 0)
            {
                temp = temp->next;
                idx--;
            }
            return temp;
        }



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

        void addFirst(int val)
        {
            node *temp = new node();
            temp->data = val;
            temp->next = head;

            if(head == NULL)
                tail = temp;
            
            head = temp;
            size++;
        }

        void addAt(int idx, int val)
        {
            node *temp = new node();
            temp->data = val;

            if(idx < 0 || idx > size)
                cout<<"Invalid arguments"<<endl;
                
            else if(idx == 0)
                addFirst(val);
                
            else if(idx == size)
                addLast(val);
            
            else
            {
                node *i = head;
                while(idx>1)
                {
                    i = i->next;
                    idx--;
                }

                temp->next = i->next;
                i->next = temp;
                
                size++;
            }
        }

        void removeLast()
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
                node *temp = head;

                while(temp->next != tail)
                    temp = temp->next;
                
                temp->next = NULL;
                tail = temp;
                size--;
            }
        }

        void removeAt(int idx)
        {
            if(idx < 0  ||  idx >= size)
                cout<<"Invalid arguments"<<endl;
            else if(head == tail)
            {
                head = NULL;
                tail = NULL;
                size--;
            }
            else if(idx == 0)
                removeFirst();

            else if(idx == size-1)
                removeLast();
                
            else
            {
                node *temp = head;
                while(idx > 1)
                {
                    temp = temp->next;
                    idx--;
                }

                temp->next = temp->next->next;
                size--;
            }
        }
        
        void reverseDI()
        {
            int left = 0;
            int right = size-1;

            while(left < right)
            {
                int temp = getNodeAt(left)->data;
                getNodeAt(left)->data = getNodeAt(right)->data;
                getNodeAt(right)->data = temp;

                left++;
                right--;
            }
        }

        void reversePI()
        {
            node *prev = NULL;
            node *curr = head;
            node *upcmg;
            
            while(curr != NULL)
            {
                upcmg = curr->next;
                curr->next = prev;

                prev = curr;
                curr = upcmg;
            }

            tail = head;
            head = prev;
        }

        int kthFromLast(int k)
        {
            if(k >= size)
            {
                cout<<"Invalid arguments"<<endl;
                return -1;
            }
                
            node *fast = head;
            node *slow = head;

            while(k--)  // forwarding fast by k elements
                fast = fast->next;
            
            while(fast != tail)     //when fast == tail,  slow == kth element from the end
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow->data;
        }

        int mid()
        {
            node *slow = head;
            node *fast = head;

            while(fast != tail && fast->next->next != NULL)// first condition for odd size, second for even size
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow->data;
        }

        LinkedList mergeTwoSortedLists(LinkedList l1, LinkedList l2)
        {
            LinkedList merged;
            int tsize = l1.showSize() + l2.showSize();
            int i=0, j=0;
            while(i < l1.showSize()  && j < l2.showSize())
            {
                if(l1.getAt(i) <= l2.getAt(j))
                {
                    merged.addLast(l1.getAt(i));
                    i++;
                }
                else
                {
                    merged.addLast(l2.getAt(j));
                    j++;
                }
            }

            if(i < l1.showSize())
                while(i<l1.showSize())
                {
                    merged.addLast(l1.getAt(i));
                    i++;
                }
            else
                while(j<l2.showSize())
                {
                    merged.addLast(l2.getAt(j));
                    j++;
                }
            
            return merged;
        }
};



int main()
{
    int n1;
    cin>>n1;
    LinkedList l1;
    int x;
    for(int i=0; i<n1; i++)
    {
        cin>>x;
        l1.addLast(x);
    }

    int n2;
    cin>>n2;
    LinkedList l2;
    for(int i=0; i<n2; i++)
    {
        cin>>x;
        l2.addLast(x);
    }

    LinkedList m;
    LinkedList merged = m.mergeTwoSortedLists(l1, l2);
    merged.display();
    l1.display();
    l2.display();

    // second way (both work)
    LinkedList n;
    n.mergeTwoSortedLists(l1, l2).display();
    l1.display();
    l2.display();

    return 0;
}