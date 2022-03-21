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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *first = head;
    ListNode *second = head;
    while(n--)
    {
        first = first->next;
    }
    //case where n < length of linked list
    if(first)
    {
        while(first->next)
        {
            first = first->next;
            second = second->next;
        }
        ListNode *node_to_delete = second->next;
        second->next = second->next->next;
        delete node_to_delete;
    }
    //case where n == length of linked list
    else if(!first)
    {
        ListNode *node_to_delete = head;
        head = head->next;
        delete node_to_delete;
    }
    return head;
}  
int main() 
{ 
    ListNode* a = NULL; 
    ListNode* res = NULL;
    int n, temp, pos;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    cin>>pos;
    res = removeNthFromEnd(a, pos);
    printList(res);
    return 0; 
} 