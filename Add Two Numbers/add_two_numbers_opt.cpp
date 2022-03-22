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
    ListNode *ptr = new ListNode(0);    
    ListNode *temp = ptr;
    int c = 0;
    while (l1 != NULL ||  l2 != NULL || c){
        int sum = 0;
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1 -> next;
        }
        if(l2 != NULL){
            sum += l2->val;
            l2 = l2 -> next;
        }
        sum += c;
        c = sum/10;
        ListNode *node = new ListNode(sum%10);
        temp -> next = node;
        temp = temp -> next;
    }
    return ptr -> next;
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