#include <bits/stdc++.h>
using namespace std;
  
class ListNode 
{ 
    public:
        int val; 
        ListNode* next;
        ListNode* prev;
        ListNode* child;
        ListNode(int a){
            val = a;
            next = NULL;
            prev= NULL;
            child =NULL;
        } 
}; 
void insertNode(ListNode* &head,int val) {
    ListNode* newNode = new ListNode(val);
    if(head == NULL) {
        head = newNode;
        head->prev = NULL;
        head->child = NULL;
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
int numComponents(ListNode* head, vector<int>& nums) {
    ListNode *curr = head;
    unordered_map<int, bool> mpp;
    for(int i=0; i<nums.size(); i++)
        mpp[nums[i]] = true;
    int count = 0, streak = 0;
    while(curr) {
        if(mpp[curr->val]==true) {
            streak++;
        } else {
            if(streak>0) {
                count++;
            }
            streak = 0;
        }
        curr = curr->next;
    }
    if(streak>0) {
        count++;
    }
    return count;
}  
int main() { 
    ListNode* a = NULL; 
    int n, m, temp, res;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    cin>>m;
    vector<int> b(m);
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    res = numComponents(a, b);
    cout<<res<<"\n";
    return 0; 
} 