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
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
            break;
    }
    if (!(fast && fast->next)) 
        return NULL;
    while (head != slow) {
        head = head->next;
        slow = slow->next;
    }
    return head;
}
ListNode* make_loop(ListNode* head, int k){
    ListNode* curr = head;
    for(int i=1; i<k; i++){
        curr = curr->next;
    }
    ListNode* kth_pos = curr;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = kth_pos;
    //a->next->next->next->next = a;
    return kth_pos;
}  
int main() 
{ 
    ListNode* a = NULL;
    ListNode* res =NULL; 
    ListNode* posn = NULL;
    int n, temp, pos;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    cin>>pos;
    if(pos>=0)
        posn= make_loop(a,pos);
    res = detectCycle(a);
    if(posn)
        cout<<true;
    else
        cout<<false;
    return 0; 
} 