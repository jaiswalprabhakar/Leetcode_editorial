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
bool isPalindrome(ListNode* head){
    int arr[100000]={-1};
    ListNode* ptr=head;
    int i=0;
    while(ptr){
        arr[i++]=ptr->val;
        ptr=ptr->next;
    }
    i--;
    ptr=head;
    while(ptr)
    {
        if(arr[i--]!=ptr->val)
        return false;
        ptr=ptr->next;
    }
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