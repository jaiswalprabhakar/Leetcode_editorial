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
ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next || !head->next->next) return head;
    
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_start = head->next;
    
    while(odd->next && even->next){
        odd->next = even->next; //Connect all odds
        even->next = odd->next->next;  //Connect all evens
        odd = odd->next;
        even = even->next;
    }
    odd->next = even_start;   //Place the first even node after the last odd node.
    return head; 
}
int main() { 
    ListNode* a = NULL;
    ListNode* result =NULL; 
    int n, temp;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    result = oddEvenList(a);
    printList(result);
    return 0; 
} 