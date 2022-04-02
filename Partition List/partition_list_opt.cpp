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
    ListNode left(0), right(0);
    ListNode *l = &left, *r = &right;

    while(head){
        ListNode* & ref = head->val < x ? l : r;
        ref->next = head;
        ref = ref->next;
        
        head = head->next;
    }
    l->next = right.next;
    r->next = NULL;
    return left.next;
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