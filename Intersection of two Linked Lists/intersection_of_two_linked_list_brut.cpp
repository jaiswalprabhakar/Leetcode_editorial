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
ListNode* make_intersection(ListNode* head, ListNode* tail, int k){
    ListNode* curr = head;
    for(int i=1; i<k; i++){
        curr = curr->next;
    }
    ListNode* tail_pos = tail;
    while(tail_pos->next != NULL)
        tail_pos = tail_pos->next;
    tail_pos->next = curr;
    return curr;
}  
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *tempA=headA;
    ListNode *tempB=headB;
    if((tempA==NULL)||(tempB==NULL))
        return NULL;
    while(tempB!=NULL)
    {
        while(tempA!=NULL)
        {
            if(tempA==tempB)
                return tempA;
            tempA=tempA->next;
        }
        tempA=headA;
        tempB=tempB->next;
    }
    return NULL;
}
int main() { 
    ListNode* a = NULL; 
    ListNode* b = NULL;
    ListNode* res = NULL;
    ListNode* pos = NULL;
    int n, m, temp,k;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    cin>>m;
    while(m--){
        cin>>temp;
        insertNode(b, temp);
    }
    cin>>k;
    if(k>0)
        pos = make_intersection(a,b, k);
    res = getIntersectionNode(a, b);
    if(res != NULL && res==pos)
        cout<<true<<"\n";
    else
        cout<<false<<"\n";
    return 0; 
} 