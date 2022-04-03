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

int widthOfBinaryTree(Node* root) {
    if(!root) return 0;
    // Node and index of the node 
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    long long int ans = 0;
    while(!q.empty())
    {
        long long int size = q.size();
        long long int min_id = q.front().second;
        long long int first, last;
        for(auto i = 0; i < size; i++)
        {
            long long int curr_id = q.front().second - min_id;
            Node *node = q.front().first;
            q.pop();
            if(i == 0) first = curr_id;
            if(i == size-1) last = curr_id;
            if(node->left)
                q.push({node->left, curr_id*2+1});
            if(node->right)
                q.push({node->right, curr_id*2+2});
        }
        
        ans = max(ans, last-first+1);
    }
    return ans;
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

    int result = widthOfBinaryTree(root);
    cout<<result;
    return 0;
}