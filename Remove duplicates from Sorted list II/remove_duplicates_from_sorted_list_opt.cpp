#include <bits/stdc++.h>
using namespace std;
  
class ListNode { 
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
void printList(ListNode *node) { 
    while (node!=NULL) { 
        cout<<node->val<<" "; 
        node = node->next; 
    } 
}

ListNode* deleteDuplicates(ListNode* head) {
    if(!head)
        return 0;
    if(!head -> next)
        return head;
    int val = head ->val;
    ListNode *temp = head -> next;
    if(temp -> val != val){
        head -> next = deleteDuplicates(temp);
        return head;
    }
    else{
        while(temp && temp -> val == val){
            ListNode *p = temp;
            temp = temp->next;
            delete p;
        }
        return deleteDuplicates(temp);
    }
}
 
int main() { 
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