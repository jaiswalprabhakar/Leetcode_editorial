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
        vector<int> arr;
        auto dummy = new ListNode(0), iter = head;
        for(; iter; iter = iter -> next) 
            arr.push_back(iter -> val);
        iter = dummy;
        for(int i = 0; i < arr.size(); i += 2) 
            iter = iter -> next = new ListNode(arr[i]);
        for(int i = 1; i < arr.size(); i += 2) 
            iter = iter -> next = new ListNode(arr[i]);
        return dummy -> next;
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