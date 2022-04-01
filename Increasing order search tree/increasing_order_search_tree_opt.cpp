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

void InOrder(Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

Node* increasingBST(Node* root, Node* tail = NULL) {
        if (!root) return tail;
        Node* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
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

    Node* result = increasingBST(root);
    InOrder(result);
    return 0;
}