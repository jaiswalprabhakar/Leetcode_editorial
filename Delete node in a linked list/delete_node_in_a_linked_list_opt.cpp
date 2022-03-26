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
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
int main() 
{ 
    ListNode* a = NULL; 
    ListNode* del = NULL;
    int n, temp, pos;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    del = a;
    cin>>pos;
    while(del !=NULL && del->val != pos){
        del = del->next;  
    }
    if(del)
        deleteNode(del);
    printList(a);
    return 0; 
} 