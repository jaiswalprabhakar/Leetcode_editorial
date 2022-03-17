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
    while(temp->next != NULL) temp = temp->next;
    
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0);
    ListNode* curr = res;
    
    while (l1 && l2)
    {
        if (l1->val < l2->val) 
        {
            insertNode(curr, l1->val);
            l1 = l1->next;
            curr = curr->next;
        }
        else 
        {
            insertNode(curr, l2->val);
            l2 = l2->next;
            curr = curr->next;
        }
    }
    while (l1) 
    {
            insertNode(curr, l1->val);
            l1 = l1->next;
            curr = curr->next;
    }
    while (l2)
    {
            insertNode(curr, l2->val);
            l2 = l2->next;
            curr = curr->next;
    }
    
    return res->next;
}
  
int main() 
{ 
    ListNode* res = NULL; 
    ListNode* a = NULL; 
    ListNode* b = NULL; 
    
    int n,m, temp;
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
  
    res = mergeTwoLists(a, b); 
  
    printList(res); 
  
    return 0; 
} 