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
ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode * temp = head;
    int length =0;
    while(temp!= NULL){
        temp = temp->next;
        length++;
    }
    if ( k%length == 0){
        return head;
    }
    int n ;
    n = k%length;
    for(int i = 1 ; i <= n ; i++ ){
        temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        temp->next->next = head;
        head = temp->next;
        temp->next = NULL;
    }
    
    return head;
}
int main() 
{ 
    ListNode* a = NULL; 
    ListNode* res=NULL;
    int n, temp, pos;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    cin>>pos;
    res = rotateRight(a, pos);
    printList(res);
    return 0; 
} 