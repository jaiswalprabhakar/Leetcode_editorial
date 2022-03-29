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
ListNode* deleteNode(ListNode* head, int element){
    if(!head) return NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(curr){
        if(head && head->val == element) head = head->next;
        if(curr && curr->val == element && prev){
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}    

ListNode* deleteDuplicates(ListNode* head) {
    if(!head) return NULL;
    ListNode* curr = head;
    unordered_set<int> s;
    while(curr && curr->next){
        if(curr->val == curr->next->val){
            s.insert(curr->val);
        }
        curr = curr->next;
    }
    for(auto x: s){
        head = deleteNode(head, x);
    }
    return head;
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