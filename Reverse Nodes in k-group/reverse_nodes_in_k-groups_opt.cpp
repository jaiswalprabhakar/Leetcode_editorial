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
ListNode* reverseKGroup(ListNode* head, int k) 
{
    if(!head)
        return NULL;
    ListNode *KSizeChecker = head;
    for(int i=0;i<k;i++)
    {
        if(KSizeChecker==NULL)
            return head;
        KSizeChecker = KSizeChecker->next;
    }
    int cnt=0;
    ListNode *cur=head,*prev=NULL,*next=NULL;
    while(cur and cnt<k)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        cnt++;
    }
    if(next)
        head->next=reverseKGroup(next,k);
    return prev;
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


