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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p = l1;
    ListNode *q = l2;
    int carry = 0;
    ListNode *dummy = new ListNode(0);
    dummy->next = NULL;
    ListNode *res = dummy;
    while(p!=NULL && q!=NULL){
        int data = p->val + q->val + carry;
        ListNode *t = new ListNode(0);
        t->next = NULL;
        t->val = data%10;
        carry = data/10;
        res->next = t;
        res = t;
        p = p->next;
        q = q->next;
    }
    while(p!=NULL){
        int data = p->val + carry;
        ListNode *t = new ListNode(0);
        t->next = NULL;
        t->val = data%10;
        carry = data/10;
        res->next = t;
        res = t;
        p = p->next;
    }
    while(q!=NULL){
        int data =  q->val + carry;
        ListNode *t = new ListNode(0);
        t->next = NULL;
        t->val = data%10;
        carry = data/10;  
        res->next = t;
        res = t;
        q = q->next;
    }
    if(carry!=0){           
        ListNode *t = new ListNode(0);
        t->next = NULL;
        t->val = carry;
        res->next = t;
        res = t;
    }
    return dummy->next;
}  
int main() { 
    ListNode* a = NULL; 
    ListNode* b = NULL;
    ListNode* res = NULL;
    int n, m, temp;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    cin>>m;
    while(m--){
        cin>>temp;
        insertNode(b, temp);
    }
    res = addTwoNumbers(a, b);
    printList(res);
    return 0; 
} 