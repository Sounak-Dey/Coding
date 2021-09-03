#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Brute force
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node *, Node *> map;
        
        // first use a hashmap to create and store a deep copy of each node
        for(auto i= head; i!=NULL; i=i->next)
        {
            Node *l2 = new Node(i->val);
            map[i] = l2;
        }
        
        //iterate through the list again again point the deep copies next and random pointers as they were int the original list
        for(auto i= head; i!=NULL; i=i->next)
        {
            map[i]->next = map[i->next];
            map[i]->random = map[i->random];
        }
        
        return map[head];
        
    }
};

//optimal
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL)
            return NULL;
        
        // insert a new copy after the current node
        for(auto i=head; i!=NULL; i=i->next->next)
        {
            Node *l2 = new Node(i->val);
            l2->next = i->next;
            i->next = l2;
        }
        
        Node *copyHead = head->next;
        

        // point the random pointers
        for(auto i=head; i!=NULL; i=i->next->next)
        {
            if(i->random != NULL)
                i->next->random = i->random->next;
        }
        
        
        //recover the original list and correctly point the copy and original lists nex pointers
        for(auto i=head; i!= NULL; i=i->next)
        {
            auto l2 = i->next;
            i->next = l2->next;
            
            if(l2->next != NULL)
                l2->next = i->next->next;    
        }
        
        return copyHead;
    }
};