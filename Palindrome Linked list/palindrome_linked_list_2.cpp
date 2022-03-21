//Hashmap method
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
bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head, *prev, *temp;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    prev = slow, slow = slow->next, prev->next = NULL;
    while (slow)
        temp = slow->next, slow->next = prev, prev = slow, slow = temp;
    fast = head, slow = prev;
    while (slow)
        if (fast->val != slow->val) return false;
        else fast = fast->next, slow = slow->next;
    return true;
}  
int main() 
{ 
    ListNode* a = NULL;  
    int n, temp;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    cout<<isPalindrome(a)<<"\n";
    return 0; 
} 