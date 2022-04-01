#include <bits/stdc++.h>
using namespace std;
  
class ListNode 
{ 
    public:
        int val; 
        ListNode* next;
        ListNode(int a){
            val = a;
            next = NULL;
        } 
}; 
void insertNode(ListNode* &head,int val) {
    ListNode* newNode = new ListNode(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while(temp->next != NULL)
     temp = temp->next;
    
    temp->next = newNode;
    return;
}
void printList(ListNode *node) 
{ 
    while (node!=NULL) 
    { 
        cout<<node->val<<" "; 
        node = node->next; 
    } 
}
ListNode* partition(ListNode* head, int x) {
    if(!head)
        return NULL;
    
    ListNode* p, *q,*r,*t;
    p=head;
    q=head->next;
    r=NULL;
    bool b=true;
    // exit from loop if no change posiible so b became false
    while(b)
    {
        b=false;
            p=head;
    q=head->next;
    r=NULL;
            // cuurent senorio r p q
        // in below while loop we swap current and last node 
        while(q)
        {
            if(q->val<x && (p->val>=x))
            {  if(head==p )
                head=q;
                if(r)
                r->next=q;
                if(p)
                p->next=q->next;
            
                q->next=p;
                
                // after swapping  the order became r q p  so swap p and q
                // swapping of p and q
                t=p;
                p=q;
                q=t;
                
                b=true;
            }
            
            // cuurent senorio r p q
                r=p;
                p=q;
                q=q->next;
            // now move forward r become p ,p becomes q and q becomes its next
            
        }
    }
    return head;
}
int main() { 
    ListNode* a = NULL;
    ListNode* result =NULL; 
    int n, temp, x;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    cin>>x;
    result = partition(a, x);
    printList(result);
    return 0; 
} 