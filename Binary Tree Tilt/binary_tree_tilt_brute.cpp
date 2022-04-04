#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
int res = 0;

void find_sum(Node* root, int &sum)
{
    if(root == NULL)
        return ;
    
    sum = sum + root->data;
    
    find_sum(root->left,sum);
    find_sum(root->right,sum);
}

void helper(Node* root)
{
    if(root == NULL)
        return ;
    
    int left_sum = 0;
    int right_sum = 0;
    
    find_sum(root->left, left_sum);
    find_sum(root->right,right_sum);
    
    res = res + abs(left_sum - right_sum);
    
    helper(root->left);
    helper(root->right);
}

int findTilt(Node* root) {
    if(root == NULL)
        return 0;
    helper(root);
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    queue<Node *> q;
    Node *root = new Node(v[0]);
    q.push(root);
    int i = 1;
    while (i < n)
    {
        Node *curr = q.front();
        q.pop();
        if (curr)
        {
            Node *temp1, *temp2;
            if (v[i] != -1)
                temp1 = new Node(v[i]);
            else
                temp1 = nullptr;
            curr->left = temp1;
            q.push(temp1);
            if (i + 1 < n)
            {
                if (v[i + 1] != -1)
                    temp2 = new Node(v[i + 1]);
                else
                    temp2 = nullptr;
                curr->right = temp2;
                q.push(temp2);
            }
            i += 2;
        }
    }

    int result = findTilt(root);
    cout<<result;
    return 0;
}