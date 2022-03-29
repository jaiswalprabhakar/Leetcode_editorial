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
ListNode* deleteDuplicates(ListNode* head) {
    if(!head)
        return NULL;
    ListNode* dummy=new ListNode(INT_MAX);
    dummy->next=head;
    ListNode* pre=dummy, *cur=head, *next=head->next;
    bool flag=false;
    while(next){
        if(next->val==cur->val){
            flag=true;
            next=next->next;
        }
        else{
            if(flag) {
                pre->next=next;
                cur=next;
                next=next->next;
            }
            else{
                pre=pre->next;
                cur=cur->next;
                next=next->next;
            }
            flag=false;
        }
    }
    //the corner cases : if the duplicate number locates at the end 
    if(flag) pre->next=next;
    return dummy->next;
}  
int main() 
{ 
    ListNode* a = NULL; 
    ListNode* res = NULL;
    int n, temp;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    res = deleteDuplicates(a);
    printList(res);
    return 0; 
} 