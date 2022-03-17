 #include <bits/stdc++.h>
using namespace std;
  
class ListNode 
{ 
    public:
    int val; 
    ListNode* next; 
}; 
  
void addNode(ListNode *head, int data){
    ListNode *ptr, *aux;
    aux = new ListNode();
    aux->val = data;
    aux->next = NULL;

    ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = aux;
}

ListNode* reverseKGroup(ListNode* head, int k, int n) 
{
    if(!head)
        return NULL;

    int len = n;
    if(len<k)
        return head;
    
    int numberOfGroupsToReverse = len/k;
    
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *start = dummyNode;

    ListNode *pre,*remaining,*next;
    for(int i=0;i<numberOfGroupsToReverse;i++)
    {
        pre = NULL;
        remaining = head;
        for(int j=0;j<k;j++)
        {
            next = head->next;
            head->next = pre;
            pre=head;
            head=next;
        }
        start->next = pre;
        remaining->next = head;
        start = remaining;
    }
    
    return dummyNode->next;
}
void push(ListNode** head_ref, int new_data) 
{ 
    ListNode* new_node = new ListNode();
    new_node->val = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
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
        push(&a, temp);
    }
    cin>>k;
    res = reverseKGroup(a, k, n); 
  
    printList(res); 
  
    return 0; 
} 

 