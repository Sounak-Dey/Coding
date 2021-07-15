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

        node *getMidNode(node *head, node *tail)
        {
            node *slow = head;
            node *fast = head;

            while(fast != tail && fast->next != tail)// (fast->next->next != NULL) will give segmentation fault
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }

        void removeNext(node *idx)
        {
            if(idx->next == tail)
            {
                idx->next = NULL;
                tail = idx;
            }
            else
                idx->next = idx->next->next;

            size--;
        }

        void displaReverseHelper(node *nd)
        {
            if(nd == NULL)
                return;
                
            displaReverseHelper(nd->next);
            cout<<nd->data<<" ";
        }

        void reversePRHelper(node *nd)
        {
            if(nd == tail)
                return;

            reversePRHelper(nd->next);
            nd->next->next = nd;
        }

        node *pleft;

        bool isPalindromeHelper(node *right)
        {
            if(right == NULL)
                return true;
                
            bool rres = isPalindromeHelper(right->next);
            
            if(pleft->data == right->data  && rres == true)
            {
                pleft = pleft->next;
                return true;
            }    
            else
                return false;
        }

        node *fleft;
        // int floor; // sir's method is better i.e to pass floor as parameter and increase at every racursive call
        void foldHelper(node *right, int floor)
        {
            if(right == NULL)
                return;

            foldHelper(right->next, floor + 1);
            
            if(floor > showSize()/2)
            {
                node *temp = fleft->next;
                fleft->next = right;
                right->next = temp;
                fleft = temp;
                // floor--;
            }
            else if(floor == showSize()/2)
            {
                right->next = NULL;
                tail = right;
                // floor--;
            }
            else 
                return;
        }

        int addTwoListsHelper(node *one, int pv1, node *two, int pv2)
        {
            if(one == NULL  &&  two == NULL)    //(pv1 == 0  &&  pv2 == 0) can also be used.
                return 0;                       // '&&' is used as a number can be NULL from the begining, if we use '||' it will return 0 at the start only
                                                // so '&&' ensures we reach the NULL for both the numbers together.

            int sum ;
            int carry;
            
            if(pv1 > pv2)
            {
                carry = addTwoListsHelper(one->next, pv1-1, two, pv2);
                sum = one->data + carry;            
            }
            else if(pv1 < pv2)
            {
                carry = addTwoListsHelper(one, pv1, two->next, pv2-1);
                sum = two->data + carry;
            }
            else
            {
                carry = addTwoListsHelper(one->next, pv1-1, two->next, pv2-1);
                sum = one->data + two->data + carry;
            }

            this->addFirst(sum % 10); 
            return sum/10;
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

        LinkedList mergeSort(node *head, node *tail)
        {
            if(head == tail)
            {
                LinkedList base;
                base.addLast(head->data);
                return base;
            }

            node *m = getMidNode(head, tail);

            LinkedList left = mergeSort(head, m);
            LinkedList right = mergeSort(m->next, tail);

            return mergeTwoSortedLists(left, right);
        }

        void removeDuplicates()
        {
            node *temp = head;
            
            while(temp != tail)
            {
                if(temp->data == temp->next->data)
                    removeNext(temp);                   
                else 
                    temp = temp->next;
            }
        }

        void oddEven()
        {
            LinkedList odd, even;
            int i=0;
            while(this->showSize() > 0)
            {
                if(this->getFirst() % 2 == 1)
                    odd.addLast(this->getFirst());
                else
                    even.addLast(this->getFirst());
                
                this->removeFirst();
            }
            
            if(odd.showSize()>0  &&  even.showSize()>0)
            {
                odd.tail->next = even.head;
                this->head = odd.head;
                this->tail = even.tail;
            }
            else if(odd.showSize()>0)
            {
                this->head = odd.head;
                this->tail = odd.tail;  
            }
            else if(even.showSize()>0)
            {
                this->head = even.head;
                this->tail = even.tail;              
            }

            this->size = odd.showSize() + even.showSize();
        }

        void kReverse(int k)
        {
            LinkedList prev;
            
            while(this->showSize()>0)
            {
                LinkedList curr;

                if(this->showSize()>k)  // when more than k elements remain
                {
                    for(int i=0; i<k; i++) // reversing k elements
                    {
                        curr.addFirst(this->getFirst());
                        this->removeFirst();
                    }
                }    
                else //when less than k elements remain
                {
                    while(this->showSize()>0)   // copying remaining elements as it is
                    {
                        curr.addLast(this->getFirst());
                        this->removeFirst();
                    }
                }
                
                if(prev.showSize() == 0) // adding first batch of k elements
                    prev = curr;
                else    //from next batch onwards
                {
                    prev.tail->next = curr.head;
                    prev.tail = curr.tail;
                    prev.size += curr.showSize();
                }
            }

            this->head = prev.head;
            this->tail = prev.tail;
            this->size = prev.showSize();
        }

        void displayReverse()
        {
            displaReverseHelper(head);
            cout<<endl;
        }

        void reversePR()
        {
            reversePRHelper(head);
            head->next = NULL;

            node *temp = head;
            head = tail;
            tail = temp;
        }

        bool isPalindrome()
        {
            pleft = head;
            return isPalindromeHelper(head);
        }

        void fold()
        {
            fleft = head;
            // floor = showSize() - 1;
            foldHelper(head, 0);
        }

        void addTwoLists(LinkedList one, LinkedList two)
        {
            int carry = addTwoListsHelper(one.head, one.showSize(), two.head, two.showSize());

            if(carry != 0)
                this->addFirst(carry);
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

    LinkedList sum;
    sum.addTwoLists(l1, l2);

    int a, b;
    cin>>a>>b;

    l1.display();
    l2.display();
    sum.display();
    sum.addFirst(a);
    sum.addLast(b);
    sum.display();
    return 0;
}