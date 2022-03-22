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
bool search(vector<int> &nums,int val1){
    int start = 0, end = nums.size()-1,mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(nums[mid] == val1){
            return true;
        }
        else if(nums[mid]>val1){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return false;
}
int numComponents(ListNode* head, vector<int>& nums) {
    ListNode *temp = head;
    bool flag = false;
    int count = 0;
    sort(nums.begin(),nums.end());
    while(temp->next != NULL){
        bool found = search(nums,temp->val);
        if(!found && flag){
            count++;
            flag = false;
        }
        else if(found){
            flag = true;   
        }
        else;
        temp = temp->next;
    }
    bool found = search(nums,temp->val);
    if(!found && flag){
        count++;
        flag = false;
    }
    else if(found){
        flag = true;
        count++;
    }
    else;
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