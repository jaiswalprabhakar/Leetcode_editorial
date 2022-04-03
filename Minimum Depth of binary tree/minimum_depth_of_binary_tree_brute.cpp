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
int minDepth(Node* root)
{
    if(root == NULL)
        return 0;
    queue < pair <Node* , int> > q;
    q.push({root , 1});
    Node* frontNode;
    int depth;
    while(!q.empty())
    {
        frontNode = q.front().first;
        depth = q.front().second;
        q.pop();
        if(frontNode->left == NULL && frontNode->right == NULL)
            return depth;
        if(frontNode->left != NULL)
            q.push({frontNode->left , depth + 1});
        if(frontNode->right != NULL)
            q.push({frontNode->right , depth + 1});
    }
    return -1;
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

    int result = minDepth(root);
    cout<<result;
    return 0;
}