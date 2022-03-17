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
bool hasCycle(ListNode *head) {
    if(head==NULL)
        return false;
    unordered_map<ListNode*,int> map;
    while(head!=NULL){
        if(map.count(head)>0)
            return true;
        else
            map[head]=1;
        head=head->next;
    }
    return false;
}
void make_loop(ListNode* head, int k){
    ListNode* curr = head;
    for(int i=1; i<k; i++){
        curr = curr->next;
    }
    ListNode* kth_pos = curr;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = kth_pos;
    //a->next->next->next->next = a;
}  
int main() 
{ 
    ListNode* a = NULL; 
    int n, temp, pos;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    cin>>pos;
    if(pos>=0)
        make_loop(a,pos);
    cout<<hasCycle(a);
    return 0; 
} 