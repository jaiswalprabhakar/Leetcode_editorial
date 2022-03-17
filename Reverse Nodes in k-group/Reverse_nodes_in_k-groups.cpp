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
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *nextptr = nullptr;
    
    while(head) {
        nextptr = head->next;
        head->next = prev;
        prev = head;
        head = nextptr;
    }
    return prev;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *dummy = new ListNode(-1), *tail = dummy;
    ListNode *nextptr = nullptr;
    tail->next = head;
    
    while(head) {
        int i = 1;
        ListNode *first_node = head;
        while(head->next && i < k) {
            head = head->next;
            ++i;
        }
        nextptr = head->next;
        head->next = nullptr;
        if(i == k) {
            tail->next = reverseList(first_node);
            first_node->next = nextptr;
            tail = first_node;
        }
        head = nextptr;
    }
    
    head = dummy->next;
    delete dummy;
    
    return head;
}  
void printList(ListNode *node) 
{ 
    while (node!=NULL) 
    { 
        cout<<node->val<<" "; 
        node = node->next; 
    } 
} 
  
int main() 
{ 
    ListNode* res = NULL; 
    ListNode* a = NULL; 
    int n, k, temp;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    cin>>k;
    res = reverseKGroup(a, k); 
  
    printList(res); 
  
    return 0; 
} 

 