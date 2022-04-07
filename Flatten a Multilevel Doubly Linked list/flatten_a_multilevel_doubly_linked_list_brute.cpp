#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *prev, *next,*child;
    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};
/*void show(Node temp)
{
    if(temp==NULL)
        return;
    cout<<temp->data<<endl;
    show(temp->child);
    show(temp->right);
}*/
void printList(Node *node) 
{ 
    while (node!=NULL) 
    { 
        cout<<node->data<<" "; 
        node = node->next; 
    } 
}
Node* flatten(Node* head, Node* rest = nullptr) {
  if (!head) return rest;
  head->next = flatten(head->child, flatten(head->next, rest));
  if (head->next) head->next->prev = head;
  head->child = nullptr;
  return head;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    Node *root=new Node(a[0]);
    Node *curr=root;
    Node *curr_root=root;
    Node *result = NULL;
    int idx=1;
    while(idx<n)
    {
        if(a[idx]==-1)
        {
            idx++;
            curr=curr_root;
            while (a[idx]==-1)
            {
                idx++;
                curr=curr->next;
            }
            curr->child=new Node(a[idx]);
            curr_root=curr;
            curr=curr->child;
            idx++;
        }
        else
        {
            curr->next=new Node(a[idx]);
            curr->next->prev=curr;
            curr=curr->next;
            idx++;
        }

    }
    result = flatten(root);
    printList(result); 
    return 0;
}