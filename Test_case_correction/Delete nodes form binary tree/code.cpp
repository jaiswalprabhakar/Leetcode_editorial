#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<Node*> res;
set<int> dp;

void util (Node* &root)
{
    if(root!=NULL)
    {
        util(root->left);
        util(root->right);
        if(dp.find(root->data)!=dp.end())
        {
            if(root->left)  res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            root=NULL;
            delete root;
        }
    }
}

vector<Node*> delNodes(Node* root, vector<int>& to_delete) {

    for(int i=0;i<to_delete.size();i++)
        dp.insert(to_delete[i]);
    util(root);
    if(root)
        res.push_back(root);
    return res;
}

void InOrder(Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    int n, m;
    cin >> n >> m;
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
    vector<int> v2;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        v2.push_back(x);
    }
    vector<Node*> v3 = delNodes(root, v2);
    for(auto node : v3){
        InOrder(node);
        cout<<endl;
    }
    return 0;
}